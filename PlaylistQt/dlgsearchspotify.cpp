#include "dlgsearchspotify.h"
#include "ui_dlgsearchspotify.h"

#include <QStringList>
#include <QString>

DlgSearchSpotify::DlgSearchSpotify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgSearchSpotify)
{
    ui->setupUi(this);
}

DlgSearchSpotify::~DlgSearchSpotify()
{
    delete ui;
}

void DlgSearchSpotify::on_pbClose_clicked()
{
   close();
}

void DlgSearchSpotify::on_pbInsert_clicked()
{
    if ( ui->lwMusics->selectedItems().size() >0) {
        for ( const auto& musicLine : ui->lwMusics->selectedItems()  ) {
            m_playlistController->addMusic( musicLine->text() );
        }
    } else if (ui->lwMusics->count()>0) {
        for (auto i =0; i< ui->lwMusics->count(); i++) {
            m_playlistController->addMusic( ui->lwMusics->item(i)->text() );
        }
    }
}


void DlgSearchSpotify::setControllers(LocalInfoController localInfoController, SpotifyController spotifyController, PlaylistController& playListController) {
    m_spotifyController = spotifyController;
    m_localInfoController = localInfoController;
    m_playlistController = &playListController;
}

void DlgSearchSpotify::on_pbSearch_clicked()
{
    m_spotifyController.login();

    if ( m_spotifyController.isLogged()) {

        QStringList listFound = m_spotifyController.search( ui->leMusicSearch->text() );

        ui->lwMusics->clear();
        ui->lwMusics->insertItems(0, listFound);
    }
}
