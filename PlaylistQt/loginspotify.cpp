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

void LoginSpotify::setLocalInfoController(LocalInfoController* localInfoController) {
    m_localInfoController = localInfoController;

    ui->leUsername->setText(m_localInfoController->getUsername());
    ui->lePassword->setText(m_localInfoController->getPassword());
}


void LoginSpotify::on_buttonBox_rejected()
{
    close();
}

void LoginSpotify::on_buttonBox_accepted()
{
    m_localInfoController->setUsername(ui->leUsername->text());
    m_localInfoController->setPassword(ui->lePassword->text());

    close();
}
