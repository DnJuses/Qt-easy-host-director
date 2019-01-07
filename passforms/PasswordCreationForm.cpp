#include "PasswordCreationForm.h"
#include "ui_PasswordCreationForm.h"

PasswordCreationForm::PasswordCreationForm(QWidget *parent) :
    AbstractPasswordForm(parent),
    ui(new Ui::PasswordCreationForm)
{
    ui->setupUi(this);
}

PasswordCreationForm::~PasswordCreationForm()
{
    delete ui;
}

bool PasswordCreationForm::checkPassValidity()
{
    return true; // Sample.
}

void PasswordCreationForm::showHash(bool mode)
{

}

void PasswordCreationForm::confirm()
{

}
