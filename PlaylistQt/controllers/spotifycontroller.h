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
    QString auxAddField(QString valAnterior, QString newField, QString separator);
    QString getMarket(QString market);
    QString getQuery(QString query);

public:

    void login();

    void getUserInfo();

    void search(QString strSearch, QString strMarket);

    // Flag
    bool isLogged() { return m_isLogged; }

private slots:
    void granted();
    void authStatusChanged(QAbstractOAuth::Status status);

signals:
    void onUpdateStatus(QAbstractOAuth::Status status);
    void onGranted(QString token);

    void onErrorLoadUserScreenName(QString errorMessage);
    void onLoadUserScreenName(QString userScreenName);

    void onSearchError(QString errorMessage);
    void onSearchResult(QJsonObject searchResult);
};

#endif // SPOTIFYCONTROLLER_H
