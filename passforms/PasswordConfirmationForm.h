#ifndef PASSWORDCONFIRMATIONFORM_H
#define PASSWORDCONFIRMATIONFORM_H

#include "AbstractPasswordForm.h"

namespace Ui {
class PasswordConfirmationForm;
}

class PasswordConfirmationForm : public AbstractPasswordForm
{
    Q_OBJECT

public:
    explicit PasswordConfirmationForm(QWidget *parent = nullptr);
    ~PasswordConfirmationForm() override;

private:
    Ui::PasswordConfirmationForm *ui;
    bool checkPassValidity() override;
private slots:
    void showHash(bool mode) override;
    void confirm() override;
};

#endif // PASSWORDCONFIRMATIONFORM_H
