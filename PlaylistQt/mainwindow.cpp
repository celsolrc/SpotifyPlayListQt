#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginspotify.h"
#include "dlgsearchspotify.h"

#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    m_localInfoController.load();
    m_playListController.setPlaylistView( ui->lwPlaylistMusic );
}

MainWindow::~MainWindow()
{
    m_localInfoController.save();

    delete ui;
}

void MainWindow::on_actionLogin_triggered()
{
    LoginSpotify loginSpotify;

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

    dlgSearchSpotify.setControllers( m_localInfoController, m_spotifyController, m_playListController);
    dlgSearchSpotify.exec();
}

void MainWindow::updateViewPlaylist(QStringList playListUpdate ) {
    ui->lwPlaylistMusic ->clear();
    ui->lwPlaylistMusic ->addItems(playListUpdate);
}


void MainWindow::on_actionNova_triggered()
{
    m_playListController.newPlaylist();
}

void MainWindow::on_actionAbrir_triggered()
{

}
