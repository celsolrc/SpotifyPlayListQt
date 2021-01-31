#include <QDesktopServices>

#include "spotifycontroller.h"

SpotifyController::SpotifyController(QObject *parent) : QObject(parent)
{
    auto replyHandler = new QOAuthHttpServerReplyHandler(8080, this);
    replyHandler->setCallbackPath("callback");
    spotify.setReplyHandler(replyHandler);

    spotify.setAuthorizationUrl(QUrl("https://accounts.spotify.com/authorize"));
    spotify.setAccessTokenUrl(QUrl("https://accounts.spotify.com/api/token"));


    spotify.setClientIdentifier("92a1d00cd68f4333bb8e0c40797bc7be");
    spotify.setClientIdentifierSharedKey("508c7765b1904848b18864cc301542a0");
    spotify.setScope("user-read-private user-top-read playlist-read-private playlist-modify-public playlist-modify-private");

    connect(&spotify, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,
                 &QDesktopServices::openUrl);

    connect(&spotify, &QOAuth2AuthorizationCodeFlow::statusChanged,
                this, &SpotifyController::authStatusChanged);

    connect(&spotify, &QOAuth2AuthorizationCodeFlow::granted,
                this, &SpotifyController::granted);
}

void SpotifyController::login()
{
    spotify.grant();
}

void SpotifyController::logout()
{
    m_isLogged = false;
}

QString SpotifyController::auxAddLabel(QString label, QString value)
{
    QString ret = "";

    if (value.length()>0)
    {
        ret = label+"="+value;
    }

    return ret;
}

QString SpotifyController::auxAddFlagField(QString valAnterior, bool flag,  QString txt)
{
    return auxAddField( valAnterior, (flag? txt: ""),  ",");
}

QString SpotifyController::auxAddField(QString valAnterior, QString newField, QString separator)
{
    if (newField.length()>0)
    {
        if (valAnterior.length()>0)
        {
            valAnterior += separator;
        }

        valAnterior += newField;
    }

    return valAnterior;
}

QString SpotifyController::getType(bool album, bool artist, bool playlist, bool track, bool show, bool episode)
{
    QString ret = "";

    ret = auxAddFlagField(ret, album, "album");
    ret = auxAddFlagField(ret, artist, "artist");
    ret = auxAddFlagField(ret, playlist, "playlist");
    ret = auxAddFlagField(ret, track, "track");
    ret = auxAddFlagField(ret, show, "show");
    ret = auxAddFlagField(ret, episode, "episode");

    ret = auxAddLabel("type", ret);

    return ret;
}

QString SpotifyController::getMarket(QString market)
{
    return auxAddLabel("market", market);
}

QString SpotifyController::getQuery(QString query)
{
    return auxAddLabel("q", query);
}

void SpotifyController::search(QString strSearch, QString strMarket, bool album, bool artist, bool playlist, bool track, bool show, bool episode)
{
    if (m_isLogged) {

        QString qrySearch = getQuery(strSearch);
        QString qryMarket = getMarket(strMarket);
        QString qryType = getType(album, artist, playlist, track, show, episode);

        QString qry = "";
        qry = auxAddField( qry, qrySearch, "&");
        qry = auxAddField( qry, qryMarket, "&");
        qry = auxAddField( qry, qryType, "&");

        QUrl u ("https://api.spotify.com/v1/search");
        u.setUrl(auxAddField( u.toString(), qry, "?"));

        auto reply = spotify.get(u);

        connect(reply, &QNetworkReply::finished, [=]() {
            if (reply->error() != QNetworkReply::NoError) {
                emit onSearchError(reply->errorString());

                return;
            }
            const auto data = reply->readAll();
            const auto document = QJsonDocument::fromJson(data);

            onSearchResult(document);

            reply->deleteLater();
        });
    }
}



//{
////    spotify.
//    // Mock
//    // Sem acesso ao Spotify. Dados fixos

//    resultSearch.clear();
//    resultSearch.append("Musica 1");
//    resultSearch.append("Musica 2");
//    resultSearch.append("Musica 3");
//    resultSearch.append("Musica 4");
//    resultSearch.append("Musica 5");
//    resultSearch.append("Musica 6");
//    resultSearch.append("Musica 7");

//    return resultSearch;
//}


void SpotifyController::granted ()
{
    m_isLogged = true;

    emit onGranted(spotify.token());
}

void SpotifyController::authStatusChanged(QAbstractOAuth::Status status)
{
    emit onUpdateStatus(status);
}

void SpotifyController::getUserInfo()
{
    if (m_isLogged) {

        emit onLoadUserInfo("Loading User Informations");

        QUrl u ("https://api.spotify.com/v1/me");

        auto reply = spotify.get(u);

        connect(reply, &QNetworkReply::finished, [=]() {
            if (reply->error() != QNetworkReply::NoError) {
                emit onLoadUserInfo(reply->errorString());
                return;
            }
            const auto data = reply->readAll();
            emit onLoadUserInfo(data);

            const auto document = QJsonDocument::fromJson(data);
            const auto root = document.object();
            const auto displayName = root.value("display_name").toString();

            onLoadUserInfo("Username: " + displayName);
            onLoadUserName(displayName);

            reply->deleteLater();
        });
    }
}
