#ifndef HOSTDIRECTORTESTMODULE_H
#define HOSTDIRECTORTESTMODULE_H
#include <QObject>

class HostDirectorTestModule : public QObject
{
    Q_OBJECT
public:
    explicit HostDirectorTestModule(QObject *parent = nullptr);
    ~HostDirectorTestModule();
    bool testPathOpenability(const QString &path);
    bool testHostsOpenability();
private:
    bool testPath(const QString &path);
};

#endif // HOSTDIRECTORTESTMODULE_H
