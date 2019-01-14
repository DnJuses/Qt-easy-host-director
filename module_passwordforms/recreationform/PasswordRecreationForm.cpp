#include "module_passwordforms/recreationform/PasswordRecreationForm.h"
#include "ui_PasswordRecreationForm.h"

PasswordRecreationForm::PasswordRecreationForm(QWidget *parent) :
    AbstractPasswordForm(parent),
    ui(new Ui::PasswordRecreationForm)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect(ui->showPassword, &QCheckBox::clicked, this, &PasswordRecreationForm::showHash);
    connect(ui->okCancel, &QDialogButtonBox::accepted, this, &PasswordRecreationForm::confirm);
    connect(ui->okCancel, &QDialogButtonBox::rejected, this, &PasswordRecreationForm::close);
}

PasswordRecreationForm::~PasswordRecreationForm()
{
    delete ui;
    this->deleteLater();
}

bool PasswordRecreationForm::checkPassValidity()
{
    const QString oldPassword = ui->oldLineEdit->text();
    const QString newPassword = ui->creationLineEdit->text();
    const QString confirmPassword = ui->confirmLineEdit->text();
    const QString realPassword = this->getPassword();
    if(oldPassword != realPassword)
    {
        PasswordNotificationTemplates::playTemplate(PasswordTemplate::Id::WRONG_OLD);
        return false;
    }
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

void PasswordRecreationForm::showHash(bool mode)
{
     QLineEdit::EchoMode echo = static_cast<QLineEdit::EchoMode>((2 * mode + 2) % 4);
    /* Echo modes for line edit:
     - 0 is normal;
     - 2 for passwords;
     - if passed false, the echo mode will be 'normal';
     - but if passed true, the echo mode will be 'password';
     - its determined by formula: (2 * mode + 2) % 4;
    */
    ui->oldLineEdit->setEchoMode(echo);
    ui->creationLineEdit->setEchoMode(echo);
    ui->confirmLineEdit->setEchoMode(echo);
}

void PasswordRecreationForm::confirm()
{
    if(checkPassValidity())
    {
        QString newPassword = ui->creationLineEdit->text();
        this->setPassword(newPassword);
        this->done(0);
    }
}
