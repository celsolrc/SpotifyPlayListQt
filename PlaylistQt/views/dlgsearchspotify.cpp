#include "dlgsearchspotify.h"
#include "ui_dlgsearchspotify.h"

#include <QStringList>
#include <QString>

DlgSearchSpotify::DlgSearchSpotify(SpotifyController& spotifyController, PlaylistController& playListController, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgSearchSpotify),
    m_spotifyController(spotifyController),
    m_playlistController(playListController)
{
    ui->setupUi(this);

    connect(&m_spotifyController, SIGNAL(onSearchError(QString)), this, SLOT(searchError(QString)) );
    connect(&m_spotifyController, SIGNAL(onSearchResult(QJsonObject)), this, SLOT(searchResult(QJsonObject)) );

    void onSearchError(QString errorMessage);
    void onSearchResult(QJsonDocument searchResult);
}

void DlgSearchSpotify::searchError(QString errorMessage)
{
    // TODO: colocar mensagem de erro
}

void DlgSearchSpotify::searchResult(QJsonObject json)
{
    // Tracks

    for (auto trackJson : json["tracks"].toObject()["items"].toArray())
    {
        Track track(trackJson.toObject());

        tracks[track.name]= track;
    }

    ui->lwMusics->clear();

    for (auto track = tracks.begin(); track != tracks.end(); ++track)
        ui->lwMusics->insertItem(0, track->name);
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
            m_playlistController.addMusic( musicLine->text() );
        }
    } else if (ui->lwMusics->count()>0) {
        for (auto i =0; i< ui->lwMusics->count(); i++) {
            m_playlistController.addMusic( ui->lwMusics->item(i)->text() );
        }
    }
}

void DlgSearchSpotify::on_pbSearch_clicked()
{

    if ( m_spotifyController.isLogged()) {

        ui->lwMusics->clear();
        m_spotifyController.search( ui->leMusicSearch->text(), ui->leMarket->text());
    }
}
