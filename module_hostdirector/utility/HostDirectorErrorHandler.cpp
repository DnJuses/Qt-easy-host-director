#include "HostDirectorErrorHandler.h"

typedef ErrorTypes::ErrorValue Error;

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
            errorString = tr("Unable to access 'hosts' file. Maybe application is blocked by antivirus?");
        break;
        case Error::CONFIGURATION_ACCESS_DENIED:
            errorString = tr("Unable to access configuration file.");
        break;
        case Error::HOSTS_COPY_FAILED:
            errorString = tr("Unable to copy 'hosts' file.");
        break;
        case Error::HOSTS_CONF_ERASE_FAILED:
            errorString = tr("Unable to erase configuration from 'hosts' file.");
        break;
        case Error::HOSTS_WRITE_FAILED:
            errorString = tr("Unable to write configuration. Timer stopped.");
        break;
        case Error::APP_ALREADY_RUNNING:
            errorString = tr("Application is already running! Only one active instance is allowed.");
        break;
    }
    QMessageBox errorNote(tr("Error"), errorCodeStr, QMessageBox::Critical, 0, 0, 0);
    errorNote.setDetailedText(errorString);
    errorNote.show();
    errorNote.exec();
}
