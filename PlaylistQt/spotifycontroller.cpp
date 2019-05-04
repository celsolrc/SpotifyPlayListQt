#include "spotifycontroller.h"

SpotifyController::SpotifyController()
{

}

void SpotifyController::login()
{
    m_isLogged = true;
}

void SpotifyController::logout()
{
    m_isLogged = false;
}

QStringList SpotifyController::search(QString strSearch)
{
    resultSearch.clear();
    resultSearch.append("Musica 1");
    resultSearch.append("Musica 2");
    resultSearch.append("Musica 3");
    resultSearch.append("Musica 4");
    resultSearch.append("Musica 5");
    resultSearch.append("Musica 6");
    resultSearch.append("Musica 7");

    return resultSearch;
}

void SpotifyController::saveLocalInfo()
{

}

void SpotifyController::loadLocalInfo()
{

}
