#include "HostDirectorErrorHandler.h"

typedef ErrorTypes::ErrorValue Error;

HostDirectorErrorHandler::HostDirectorErrorHandler(QObject *parent) : QObject(parent)
{

}

void HostDirectorErrorHandler::dispatchError(ErrorTypes::ErrorValue errorCode)
{
    switch(errorCode)
    {
        case Error::WRONG_CONF_FILE_PATH:
         break;

        case Error::HOSTS_ACCESS_DENIED:
         break;

        default:
        // Lets hope we dont end up here
        break;
    }
}
