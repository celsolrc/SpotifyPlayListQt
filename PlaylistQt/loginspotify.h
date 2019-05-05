#ifndef LOGINSPOTIFY_H
#define LOGINSPOTIFY_H

#include <QDialog>

#include "localinfocontroller.h"

namespace Ui {
class LoginSpotify;
}

class LoginSpotify : public QDialog
{
    Q_OBJECT

public:
    explicit LoginSpotify(QWidget *parent = nullptr);
    ~LoginSpotify();

    void setLocalInfoController(LocalInfoController* localInfoController);

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();

private:
    Ui::LoginSpotify *ui;

    LocalInfoController* m_localInfoController;
};

#endif // LOGINSPOTIFY_H
