#include "HostDirectorTestModule.h"
#include <QFile>

typedef ErrorTypes::ErrorValue Error;
extern const QString HOSTS_PATH = QString::fromLocal8Bit(qgetenv("windir")) + QString("\\System32\\drivers\\etc\\hosts");

HostDirectorTestModule::HostDirectorTestModule(QObject *parent) : QObject(parent)
{
}

bool HostDirectorTestModule::testPath(const QString &path)
{
    if(path.length() <= 0 || (!path.endsWith(".hdcf") && !path.endsWith(".txt")))
    {
        emit handleError(Error::WRONG_CONF_FILE_PATH);
        return false;
    }
    return true;
}

bool HostDirectorTestModule::testHostsOpenability()
{
    QFile hostsFile(HOSTS_PATH);
    if(!hostsFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        emit handleError(Error::HOSTS_ACCESS_DENIED);
        return false;
    }
    hostsFile.close();
    return false;
}
