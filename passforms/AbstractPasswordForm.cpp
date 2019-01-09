#include "AbstractPasswordForm.h"
#include <QSettings>

bool AbstractPasswordForm::isPasswordExists()
{
    return QSettings().value(HostConstant::PASSWORD_REGISTRY_KEY, "") != "";
}

AbstractPasswordForm::AbstractPasswordForm(QWidget *parent) : QDialog(parent)
{

}

AbstractPasswordForm::~AbstractPasswordForm()
{

}

void AbstractPasswordForm::setPassword(QString &message)
{
    QSettings().setValue(HostConstant::PASSWORD_REGISTRY_KEY, encryptPassword(message));
}

QString AbstractPasswordForm::getPassword()
{
    // Maximum password length is 30 chars, so 60 bytes will be copied at worst scenario.
    QString encryptedPassword = QSettings().value(HostConstant::PASSWORD_REGISTRY_KEY, "").toString();
    return decryptPassword(encryptedPassword);
}

QString AbstractPasswordForm::encryptPassword(QString &message)
{
    for(size_t i = 0; i < message.length(); i++)
    {
        quint16 charCode = message[i].unicode();
        message[i] = charCode ^ HostConstant::XOR_KEY;
    }
    return message;
}

QString AbstractPasswordForm::decryptPassword(QString &message)
{
    return encryptPassword(message);
}
