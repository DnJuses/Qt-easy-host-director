#ifndef HOSTDIRECTORERRORHANDLER_H
#define HOSTDIRECTORERRORHANDLER_H

#include "module_hostdirector/utility/ErrorTypes.h"
#include <QObject>
#include <QMessageBox>

class HostDirectorErrorHandler : public QObject
{
    Q_OBJECT
public:
    static void dispatchError(ErrorTypes::ErrorValue errorCode);
private:
    HostDirectorErrorHandler();
};

#endif // HOSTDIRECTORERRORHANDLER_H
