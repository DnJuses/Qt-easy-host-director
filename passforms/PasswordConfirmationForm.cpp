#include "PasswordConfirmationForm.h"
#include "ui_PasswordConfirmationForm.h"

PasswordConfirmationForm::PasswordConfirmationForm(QWidget *parent) :
    AbstractPasswordForm (parent),
    ui(new Ui::PasswordConfirmationForm)
{
    ui->setupUi(this);
}

PasswordConfirmationForm::~PasswordConfirmationForm()
{
    delete ui;
}

bool PasswordConfirmationForm::checkPassValidity()
{
    return true; // Sample.
}

void PasswordConfirmationForm::showHash(bool mode)
{

}

void PasswordConfirmationForm::confirm()
{

}
