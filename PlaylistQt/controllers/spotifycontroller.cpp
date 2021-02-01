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

QString SpotifyController::auxAddLabel(QString label, QString value)
{
    QString ret = "";

    if (value.length()>0)
    {
        ret = label+"="+value;
    }

    return ret;
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

QString SpotifyController::getMarket(QString market)
{
    return auxAddLabel("market", market);
}

QString SpotifyController::getQuery(QString query)
{
    return auxAddLabel("q", query);
}

void SpotifyController::search(QString strSearch, QString strMarket)
{
    if (m_isLogged) {

        QString qrySearch = getQuery(strSearch);
        QString qryMarket = getMarket(strMarket);
        QString qryType = "type=track";

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
            const auto root = document.object();

            onSearchResult(root);

            reply->deleteLater();
        });
    }
}

void SpotifyController::granted ()
{
    m_isLogged = true;

    emit onGranted(spotify.token());

    getUserInfo();
}

void SpotifyController::authStatusChanged(QAbstractOAuth::Status status)
{
    if ( (status == QAbstractOAuth::Status::Granted) || (status == QAbstractOAuth::Status::TemporaryCredentialsReceived) )
        m_isLogged = true;
    else if (status == QAbstractOAuth::Status::NotAuthenticated)
        m_isLogged = false;

    emit onUpdateStatus(status);
}

void SpotifyController::getUserInfo()
{
    if (m_isLogged) {

        QUrl u ("https://api.spotify.com/v1/me");

        auto reply = spotify.get(u);

        connect(reply, &QNetworkReply::finished, [=]() {
            if (reply->error() != QNetworkReply::NoError) {
                emit onErrorLoadUserScreenName(reply->errorString());
                return;
            }
            const auto data = reply->readAll();

            const auto document = QJsonDocument::fromJson(data);
            const auto root = document.object();
            const auto displayName = root.value("display_name").toString();

            onLoadUserScreenName(displayName);

            reply->deleteLater();
        });
    }
}
