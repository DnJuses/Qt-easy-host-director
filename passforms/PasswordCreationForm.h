#ifndef PASSWORDCREATIONFORM_H
#define PASSWORDCREATIONFORM_H

#include "AbstractPasswordForm.h"

namespace Ui {
class PasswordCreationForm;
}

class PasswordCreationForm : public AbstractPasswordForm
{
    Q_OBJECT

public:
    explicit PasswordCreationForm(QWidget *parent = nullptr);
    ~PasswordCreationForm() override;

private:
    Ui::PasswordCreationForm *ui;
    bool checkPassValidity() override;
private slots:
    void showHash(bool mode) override;
    void confirm() override;
};

#endif // PASSWORDCREATIONFORM_H
