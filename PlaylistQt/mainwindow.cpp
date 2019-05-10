#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginspotify.h"
#include "dlgsearchspotify.h"

#include <QStringList>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    m_localInfoController.load();
//    m_playListController.setPlaylistView( ui->lwPlaylistMusic );

    connect(&m_playListController, SIGNAL(updatePlaylist(QStringList)), this, SLOT(on_UpdatePlayList(QStringList)) );

    if (m_localInfoController.haveLocalInfo()) {
        m_playListController.setPlaylistName(m_localInfoController.getLastPlayListName());
        m_playListController.loadPlaylist();
    } else {
        m_playListController.newPlaylist();
    }
}

MainWindow::~MainWindow()
{
    m_localInfoController.save();

    delete ui;
}

void MainWindow::on_actionLogin_triggered()
{
    LoginSpotify loginSpotify;

    loginSpotify.setLocalInfoController(&m_localInfoController);
    loginSpotify.setModal(true);
    loginSpotify.exec();
}

void MainWindow::on_actionSair_triggered()
{
    close();
}

void MainWindow::on_actionSearch_triggered()
{
    DlgSearchSpotify dlgSearchSpotify;

    dlgSearchSpotify.setControllers( m_spotifyController, m_playListController);
    dlgSearchSpotify.exec();
}

void MainWindow::updateViewPlaylist(QStringList playListUpdate ) {
    ui->lwPlaylistMusic ->clear();
    ui->lwPlaylistMusic ->addItems(playListUpdate);
}


void MainWindow::on_UpdatePlayList(QStringList playlist)
{
    ui->lwPlaylistMusic ->clear();
    ui->lwPlaylistMusic ->addItems(playlist);
}

void MainWindow::on_actionNova_triggered()
{
    m_localInfoController.setLastPlayListName("");
    m_playListController.newPlaylist();
}

void MainWindow::on_actionAbrir_triggered()
{
    QString filter="Playlists (*.pls) ;; Todos (*.*)";
    QString openFile = QFileDialog::getOpenFileName(this, "Abrir Playlist", QDir::homePath(), filter);

    if (openFile.length()>0) {
        m_playListController.setPlaylistName(openFile);
        m_playListController.loadPlaylist();

        m_localInfoController.setLastPlayListName(openFile);
        // TODO: falta tratar falha na leitura
    }
}

void MainWindow::on_actionSalvar_triggered()
{
    QString filter="Playlists (*.pls) ;; Todos (*.*)";
    QString saveFile = QFileDialog::getSaveFileName(this, "Salvar Playlist", QDir::homePath(), filter);

    if (saveFile.length()>0) {
        m_playListController.setPlaylistName(saveFile);
        m_playListController.savePlaylist();

        m_localInfoController.setLastPlayListName(saveFile);
        // TODO: falta tratar falha na gravacao
    }
}

void MainWindow::on_actionLogout_triggered()
{
    m_localInfoController.setUsername("");
    m_localInfoController.setPassword("");

    m_spotifyController.logout();
}
