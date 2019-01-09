#include "PasswordCreationForm.h"
#include "ui_PasswordCreationForm.h"
#include <QMessageBox>

PasswordCreationForm::PasswordCreationForm(QWidget *parent) :
    AbstractPasswordForm(parent),
    ui(new Ui::PasswordCreationForm)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect(ui->showPassword, &QCheckBox::clicked, this, &PasswordCreationForm::showHash);
    connect(ui->okCancel, &QDialogButtonBox::accepted, this, &PasswordCreationForm::confirm);
    connect(ui->okCancel, &QDialogButtonBox::rejected, this, &PasswordCreationForm::close);
}

PasswordCreationForm::~PasswordCreationForm()
{
    delete ui;
    this->deleteLater();
}

bool PasswordCreationForm::checkPassValidity()
{
    const QString newPassword = ui->creationLineEdit->text();
    const QString confirmPassword = ui->confirmLineEdit->text();
    if(newPassword == confirmPassword && newPassword.length() == 0)
    {
        PasswordNotificationTemplates::playTemplate(PasswordTemplate::Id::EMPTY_PASSWORDS);
        return true;
    }
    else if(newPassword == confirmPassword)
    {
        PasswordNotificationTemplates::playTemplate(PasswordTemplate::Id::CREATED_SUCCESSFULLY);
        return true;
    }
    else
    {
        PasswordNotificationTemplates::playTemplate(PasswordTemplate::Id::WRONG_CONFIRM);
        return false;
    }
}

void PasswordCreationForm::showHash(bool mode)
{
    QLineEdit::EchoMode echo = static_cast<QLineEdit::EchoMode>((2 * mode + 2) % 4);
    /* Echo modes for line edit:
     - 0 is normal;
     - 2 for passwords;
     - if passed false, the echo mode will be 'normal';
     - but if passed true, the echo mode will be 'password';
     - its determined by formula: (2 * mode + 2) % 4;
    */
     ui->creationLineEdit->setEchoMode(echo);
     ui->confirmLineEdit->setEchoMode(echo);
}

void PasswordCreationForm::confirm()
{
    if(checkPassValidity())
    {
        QString newPassword = ui->creationLineEdit->text();
        this->setPassword(newPassword);
        this->done(0);
    }
}
