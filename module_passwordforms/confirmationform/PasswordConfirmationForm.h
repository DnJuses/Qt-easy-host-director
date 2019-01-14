#ifndef PASSWORDCONFIRMATIONFORM_H
#define PASSWORDCONFIRMATIONFORM_H

#include "module_passwordforms/AbstractPasswordForm.h"

namespace Ui {
class PasswordConfirmationForm;
}

class PasswordConfirmationForm : public AbstractPasswordForm
{
    Q_OBJECT

public:
    explicit PasswordConfirmationForm(QWidget *parent = nullptr);
    ~PasswordConfirmationForm() override;
    bool isCorrect() const;
private:
    Ui::PasswordConfirmationForm *ui;
    bool checkPassValidity() override;
    bool correct;
private slots:
    void showHash(bool mode) override;
    void confirm() override;
};

#endif // PASSWORDCONFIRMATIONFORM_H
