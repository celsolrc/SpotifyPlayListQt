#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "localinfocontroller.h"
#include "spotifycontroller.h"
#include "playlistcontroller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionLogin_triggered();

    void on_actionSair_triggered();

    void on_actionSearch_triggered();

    void updateViewPlaylist(QStringList playListUpdate );


    void on_actionNova_triggered();

    void on_actionAbrir_triggered();

    void on_actionSalvar_triggered();

    void on_actionLogout_triggered();

private:
    Ui::MainWindow *ui;

    LocalInfoController m_localInfoController;
    SpotifyController m_spotifyController;
    PlaylistController m_playListController;
};

#endif // MAINWINDOW_H
