#ifndef PLAYLISTCONTROLLER_H
#define PLAYLISTCONTROLLER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QListWidget>

#define D_VERSION_PLAYLIST "0.01"
#define D_FILEEXT_PLAYLIST ".pls"

class PlaylistController : public QObject
{
    Q_OBJECT

private:
    QStringList m_playlist;

    QString m_playListName;

    bool m_isLoad = false;
    bool m_isSaved = false;

    void fixExtensionFile();

    // View Management
    void updateView();

public:
    explicit PlaylistController(QObject *parent = nullptr);

    // Playlist Methods
    void newPlaylist() { m_isLoad = false; m_isSaved=false; setPlaylistName("noname"); m_playlist.clear(); updateView(); }
    bool loadPlaylist();
    bool savePlaylist();

    //Get/Set
    void setPlaylistName(QString playlistName) { m_playListName = playlistName; fixExtensionFile(); }
    QString getPlaylistName() { return m_playListName; }

    // Flags
    bool isLoaded() { return m_isLoad; }
    bool isSaved() { return m_isSaved; }

    bool havePlayList() { return (m_playlist.size()  > 0); }

    // Playlist management
    QStringList getPlaylist() { return m_playlist; }

    void addMusic(QString musicName ) { m_playlist.append(musicName); updateView(); }
    void addMusic(QStringList musicListNames ) { m_playlist.append(musicListNames); updateView(); }
    void deleteMusic(int pos) { m_playlist.removeAt(pos); updateView(); }

    void clearMusics() { m_playlist.clear(); updateView(); }

signals:
    void updatePlaylist(QStringList playlist);

public slots:

};

#endif // PLAYLISTCONTROLLER_H
