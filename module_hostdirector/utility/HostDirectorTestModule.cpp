#include "HostDirectorConstants.h"
#include "HostDirectorErrorHandler.h"
#include "HostDirectorTestModule.h"
#include <QFile>

typedef ErrorTypes::ErrorValue Error;

HostDirectorTestModule::HostDirectorTestModule(QObject *parent) : QObject(parent)
{

}

HostDirectorTestModule::~HostDirectorTestModule()
{
    this->deleteLater();
}

bool HostDirectorTestModule::testPath(const QString &path)
{
    if(path.length() <= 0 || (!path.endsWith(".hdcf") && !path.endsWith(".txt")))
    {
        HostDirectorErrorHandler::dispatchError(Error::WRONG_CONF_FILE_PATH);
        return false;
    }
    return true;
}

bool HostDirectorTestModule::testPathOpenability(const QString &path)
{
    if(!testPath(path))
        return false;
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        HostDirectorErrorHandler::dispatchError(Error::CONFIGURATION_ACCESS_DENIED);
        return false;
    }
    return true;
}

bool HostDirectorTestModule::testHostsOpenability()
{
    QFile hostsFile(HostConstant::HOSTS_PATH);
    if(!hostsFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        HostDirectorErrorHandler::dispatchError(Error::HOSTS_ACCESS_DENIED);
        return false;
    }
    hostsFile.close();
    return true;
}
