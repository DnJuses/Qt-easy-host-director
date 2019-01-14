#ifndef ABSTRACTPASSWORDFORM_H
#define ABSTRACTPASSWORDFORM_H
#include "module_hostdirector/utility/HostDirectorConstants.h"
#include "module_passwordforms/utility/PasswordNotificationTemplates.h"
#include <QDialog>


class AbstractPasswordForm : public QDialog
{
    Q_OBJECT
public:
    static bool isPasswordExists();
protected:
    AbstractPasswordForm(QWidget *parent = nullptr);
    virtual ~AbstractPasswordForm();
    virtual bool checkPassValidity() = 0;
    void setPassword(QString &message);
    QString getPassword();
protected slots:
    virtual void showHash(bool mode) = 0;
    virtual void confirm() = 0;
private:
    QString encryptPassword(QString &message);
    QString decryptPassword(QString &message);
};

#endif // ABSTRACTPASSWORDFORM_H
