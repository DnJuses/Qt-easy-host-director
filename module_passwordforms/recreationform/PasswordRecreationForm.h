#ifndef PASSWORDRECREATIONFORM_H
#define PASSWORDRECREATIONFORM_H

#include "module_passwordforms/AbstractPasswordForm.h"

namespace Ui {
class PasswordRecreationForm;
}

class PasswordRecreationForm : public AbstractPasswordForm
{
    Q_OBJECT

public:
    explicit PasswordRecreationForm(QWidget *parent = nullptr);
    ~PasswordRecreationForm() override;

private:
    Ui::PasswordRecreationForm *ui;
    bool checkPassValidity() override;
private slots:
    void showHash(bool mode) override;
    void confirm() override;
};

#endif // PASSWORDRECREATIONFORM_H
