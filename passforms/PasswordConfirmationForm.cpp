#include "PasswordConfirmationForm.h"
#include "ui_PasswordConfirmationForm.h"
#include <QDebug>
#include <QMessageBox>
#include <QSettings>

PasswordConfirmationForm::PasswordConfirmationForm(QWidget *parent) :
    AbstractPasswordForm (parent),
    ui(new Ui::PasswordConfirmationForm),
    correct(false)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect(ui->showPassword, &QCheckBox::clicked, this, &PasswordConfirmationForm::showHash);
    connect(ui->okCancel, &QDialogButtonBox::accepted, this, &PasswordConfirmationForm::confirm);
    connect(ui->okCancel, &QDialogButtonBox::accepted, this, &PasswordConfirmationForm::close);
}

PasswordConfirmationForm::~PasswordConfirmationForm()
{
    delete ui;
    this->deleteLater();
}

bool PasswordConfirmationForm::isCorrect() const
{
    return correct;
}

bool PasswordConfirmationForm::checkPassValidity()
{
    const QString writtenPass = ui->confirmLineEdit->text();
    const QString realPass = this->getPassword();
    if(writtenPass == realPass)
    {
        return true;
    }
    PasswordNotificationTemplates::playTemplate(PasswordTemplate::Id::WRONG_CONFIRM);
    return false;
}

void PasswordConfirmationForm::showHash(bool mode)
{
    QLineEdit::EchoMode echo = static_cast<QLineEdit::EchoMode>((2 * mode + 2) % 4);
    /* Echo modes for line edit:
     - 0 is normal;
     - 2 for passwords;
     - if passed false, the echo mode will be 'normal';
     - but if passed true, the echo mode will be 'password';
     - its determined by formula: (2 * mode + 2) % 4;
    */
    ui->confirmLineEdit->setEchoMode(echo);
}

void PasswordConfirmationForm::confirm()
{
    if(checkPassValidity())
    {
        correct = true;
        this->done(0);
    }
}
