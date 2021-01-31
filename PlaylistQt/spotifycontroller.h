#ifndef SPOTIFYCONTROLLER_H
#define SPOTIFYCONTROLLER_H

#include <QObject>
#include <QtNetwork>
#include <QtNetworkAuth>
#include <QString>
#include <QStringList>

#include <QPlainTextEdit>


class SpotifyController  : public QObject
{
    Q_OBJECT
public:
    explicit SpotifyController(QObject *parent = nullptr);

private:

    // Statos conexão
    bool m_isLogged = false;

    // Resultado da busca
    QStringList resultSearch;

    QOAuth2AuthorizationCodeFlow spotify;

    QString auxAddLabel(QString label, QString value);
    QString auxAddFlagField(QString valAnterior, bool flag,  QString txt);
    QString auxAddField(QString valAnterior, QString newField, QString separator);
    QString getType(bool album, bool artist, bool playlist, bool track, bool show, bool episode);
    QString getMarket(QString market);
    QString getQuery(QString query);

public:

    void login();
    void logout();

    void getUserInfo();

    void search(QString strSearch, QString strMarket, bool album, bool artist, bool playlist, bool track, bool show, bool episode);

    // Flag
    bool isLogged() { return m_isLogged; }

private slots:
    void granted();

    void authStatusChanged(QAbstractOAuth::Status status);

signals:
    void onUpdateStatus(QAbstractOAuth::Status status);
    void onGranted(QString token);

    void onLoadUserInfo(QString lineUserInfo);
    void onLoadUserName(QString userName);

    void onSearchError(QString errorMessage);
    void onSearchResult(QJsonDocument searchResult);
};

#endif // SPOTIFYCONTROLLER_H
