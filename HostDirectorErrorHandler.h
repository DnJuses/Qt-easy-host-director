#ifndef HOSTDIRECTORERRORHANDLER_H
#define HOSTDIRECTORERRORHANDLER_H

#include "ErrorTypes.h"
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
