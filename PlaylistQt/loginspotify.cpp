#include "loginspotify.h"
#include "ui_loginspotify.h"

LoginSpotify::LoginSpotify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginSpotify)
{
    ui->setupUi(this);
}

LoginSpotify::~LoginSpotify()
{
    delete ui;
}

void LoginSpotify::on_buttonBox_rejected()
{
    close();
}

void LoginSpotify::on_buttonBox_accepted()
{
    close();
}
