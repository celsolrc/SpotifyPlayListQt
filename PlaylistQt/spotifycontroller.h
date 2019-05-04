#ifndef SPOTIFYCONTROLLER_H
#define SPOTIFYCONTROLLER_H

#include<QString>
#include <QStringList>


class SpotifyController
{
private:

    // Statos conexão
    bool m_isLogged = false;

    // Informacoes de login
    QString m_userName;
    QString m_password;


    // Executa login com as informações de usuario/senha
    bool makeLogin();

    // desconecta do Spotify
    bool makeLogout();


    // Resultado da busca
    QStringList resultSearch;


public:
    SpotifyController();

    // Gets
    void setUserName(QString userName) { m_userName = userName; }
    void setPassword(QString password) { m_password = password; }

    // Sets
    QString getUserName() { return m_userName; }
    QString getPassword() { return m_password; }


    void login();
    void logout();

    bool isLogged() { return m_isLogged; }

    QStringList search(QString strSearch);

    void saveLocalInfo();
    void loadLocalInfo();
};

#endif // SPOTIFYCONTROLLER_H
