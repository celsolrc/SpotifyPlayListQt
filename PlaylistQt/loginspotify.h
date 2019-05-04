#ifndef LOGINSPOTIFY_H
#define LOGINSPOTIFY_H

#include <QDialog>

namespace Ui {
class LoginSpotify;
}

class LoginSpotify : public QDialog
{
    Q_OBJECT

public:
    explicit LoginSpotify(QWidget *parent = nullptr);
    ~LoginSpotify();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::LoginSpotify *ui;
};

#endif // LOGINSPOTIFY_H
