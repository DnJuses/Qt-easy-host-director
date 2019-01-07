#ifndef ABSTRACTPASSWORDFORM_H
#define ABSTRACTPASSWORDFORM_H
#include <QDialog>
#include <QAbstractButton>
class AbstractPasswordForm : public QDialog
{
    Q_OBJECT
protected:
    AbstractPasswordForm(QWidget *parent = nullptr);
    virtual ~AbstractPasswordForm();
    virtual bool checkPassValidity() = 0;
    QString passEncrypt(QString &message);
    QString passDecrypt(QString &message);
protected slots:
    virtual void showHash(bool mode) = 0;
    virtual void confirm() = 0;
};

#endif // ABSTRACTPASSWORDFORM_H
