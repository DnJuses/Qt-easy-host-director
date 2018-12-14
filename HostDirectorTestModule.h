#ifndef HOSTDIRECTORTESTMODULE_H
#define HOSTDIRECTORTESTMODULE_H
#include "ErrorTypes.h"
#include <QObject>

class HostDirectorTestModule : public QObject
{
    Q_OBJECT
private:
    bool testPath(const QString &path);
public:
    explicit HostDirectorTestModule(QObject *parent = nullptr);
    bool testPathOpenability(const QString &path);
    bool testHostsOpenability();
signals:
    void handleError(ErrorTypes::ErrorValue);
};

#endif // HOSTDIRECTORTESTMODULE_H
