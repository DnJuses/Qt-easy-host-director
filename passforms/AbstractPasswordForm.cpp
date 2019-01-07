#include "AbstractPasswordForm.h"
#include "HostDirectorConstants.h"

AbstractPasswordForm::AbstractPasswordForm(QWidget *parent) : QDialog(parent)
{

}

AbstractPasswordForm::~AbstractPasswordForm()
{

}

QString AbstractPasswordForm::passEncrypt(QString &message)
{
    for(size_t i = 0; i < message.length(); i++)
    {
        quint16 charCode = message[i].unicode();
        message[i] = charCode ^ HostConstant::XOR_KEY;
    }
    return message;
}

QString AbstractPasswordForm::passDecrypt(QString &message)
{
    return passEncrypt(message);
}
