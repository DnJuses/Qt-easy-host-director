#include "HostDirectorErrorHandler.h"
#include <QDebug>

typedef ErrorTypes::ErrorValue Error;


HostDirectorErrorHandler::HostDirectorErrorHandler(QObject *parent) : QObject(parent)
{
}

void HostDirectorErrorHandler::dispatchError(ErrorTypes::ErrorValue errorCode)
{
    const QString errorCodeStr = tr("Error code: %1 \n").arg(QString::number(static_cast<quint16>(errorCode)));
    QString errorString;
    switch(errorCode)
    {
        case Error::WRONG_CONF_FILE_PATH:
            errorString = tr("Given file is not a configuration file.");
        break;
        case Error::HOSTS_ACCESS_DENIED:
            errorString = tr("Cannot access to 'hosts' file. Maybe it blocked by antivirus?");
        break;
    }
    QMessageBox errorNote(tr("Error"), errorCodeStr, QMessageBox::Critical, 0, 0, 0);
    errorNote.setDetailedText(errorString);
    errorNote.show();
    errorNote.exec();
}
