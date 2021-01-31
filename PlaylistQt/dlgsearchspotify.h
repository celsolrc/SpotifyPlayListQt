#ifndef DLGSEARCHSPOTIFY_H
#define DLGSEARCHSPOTIFY_H

#include <QDialog>

#include <spotifycontroller.h>
#include <localinfocontroller.h>
#include <playlistcontroller.h>

namespace Ui {
class DlgSearchSpotify;
}

class DlgSearchSpotify : public QDialog
{
    Q_OBJECT

public:
    explicit DlgSearchSpotify(SpotifyController& spotifyController, PlaylistController& playlistController, QWidget *parent = nullptr);
    ~DlgSearchSpotify();


private slots:

    void on_pbClose_clicked();
    void on_pbInsert_clicked();
    void on_pbSearch_clicked();

    void searchError(QString errorMessage);
    void searchResult(QJsonDocument searchResult);

private:
    Ui::DlgSearchSpotify *ui;

    SpotifyController& m_spotifyController;
    PlaylistController& m_playlistController;
};

#endif // DLGSEARCHSPOTIFY_H
