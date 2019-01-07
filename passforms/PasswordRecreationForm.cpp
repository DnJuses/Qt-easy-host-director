#include "PasswordRecreationForm.h"
#include "ui_PasswordRecreationForm.h"

PasswordRecreationForm::PasswordRecreationForm(QWidget *parent) :
    AbstractPasswordForm(parent),
    ui(new Ui::PasswordRecreationForm)
{
    ui->setupUi(this);
}

PasswordRecreationForm::~PasswordRecreationForm()
{
    delete ui;
}

bool PasswordRecreationForm::checkPassValidity()
{
    return true; // Sample.
}

void PasswordRecreationForm::showHash(bool mode)
{

}

void PasswordRecreationForm::confirm()
{

}
