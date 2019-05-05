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
    explicit DlgSearchSpotify(QWidget *parent = nullptr);
    ~DlgSearchSpotify();

    void setControllers(SpotifyController spotifyController, PlaylistController &playListController);

private slots:

    void on_pbClose_clicked();
    void on_pbInsert_clicked();
    void on_pbSearch_clicked();

private:
    Ui::DlgSearchSpotify *ui;

    SpotifyController m_spotifyController;
    PlaylistController* m_playlistController;
};

#endif // DLGSEARCHSPOTIFY_H
