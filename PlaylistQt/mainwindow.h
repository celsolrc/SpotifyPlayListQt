#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controllers/localinfocontroller.h"
#include "controllers/spotifycontroller.h"
#include "controllers/playlistcontroller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateViewPlaylist(QStringList playListUpdate );

private slots:
    void on_actionLogin_triggered();
    void on_actionSair_triggered();
    void on_actionSearch_triggered();
    void on_actionNova_triggered();
    void on_actionAbrir_triggered();
    void on_actionSalvar_triggered();

    void on_UpdatePlayList(QStringList playlist);

    void authStatusChanged(QAbstractOAuth::Status status);

    void loadUserScreenName(QString userName);


private:
    Ui::MainWindow *ui;

    LocalInfoController m_localInfoController;
    SpotifyController m_spotifyController;
    PlaylistController m_playListController;

    void updateMenu();
};

#endif // MAINWINDOW_H
