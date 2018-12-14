#ifndef HOSTDIRECTORERRORHANDLER_H
#define HOSTDIRECTORERRORHANDLER_H

#include "ErrorTypes.h"
#include <QObject>
#include <QMessageBox>

class HostDirectorErrorHandler : public QObject
{
    Q_OBJECT
public:
    explicit HostDirectorErrorHandler(QObject *parent = nullptr);
public slots:
    void dispatchError(ErrorTypes::ErrorValue errorCode);
};

#endif // HOSTDIRECTORERRORHANDLER_H
