#ifndef HOSTDIRECTORTESTMODULE_H
#define HOSTDIRECTORTESTMODULE_H
#include "ErrorTypes.h"
#include <QObject>

class HostDirectorTestModule : public QObject
{
    Q_OBJECT
public:
    explicit HostDirectorTestModule(QObject *parent = nullptr);
    bool testPath(const QString &path);
    bool testHostsOpenability();
signals:
    void handleError(ErrorTypes::ErrorValue);
};

#endif // HOSTDIRECTORTESTMODULE_H
