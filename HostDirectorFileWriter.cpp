#include "HostDirectorFileWriter.h"
#include "HostDirectorErrorHandler.h"
#include "HostDirectorConstants.h"
#include <QDir>

typedef ErrorTypes::ErrorValue Error;

QFile HostDirectorFileWriter::hostsCopy("temp/hosts_copy");

HostDirectorFileWriter::HostDirectorFileWriter(QObject *parent) : QObject(parent)
{
    if(!QDir().exists("temp"))
    {
        QDir().mkdir("temp");
    }
}

bool HostDirectorFileWriter::writeConfiguration(const QString &confPath)
{
    QFile hostsFile(HostConstant::HOSTS_PATH);
    QFile confFile(confPath);
    if(this->isCopyExists())
    {
        hostsCopy.remove();
    }
    if(!this->createHostsCopy(hostsFile))
    {
        return false;
    }
    if(hostsFile.open(QIODevice::Append | QIODevice::Text) && confFile.open(QIODevice::ReadOnly))
    {
        const QByteArray signBegin = "\n#<Host Director temporary>\n";
        const QByteArray signEnd = "\n#</Host Director temporary>\n";
        if(hostsFile.write(signBegin + confFile.readAll() + signEnd))
        {
            return true;
        }
    }
    HostDirectorErrorHandler::dispatchError(Error::HOSTS_WRITE_FAILED);
    return false;
}

void HostDirectorFileWriter::writePermanentConfiguration(const QString &confPath)
{
    QFile hostsFile(HostConstant::HOSTS_PATH);
    QFile confFile(confPath);
    if(hostsFile.open(QIODevice::Append | QIODevice::Text) && confFile.open(QIODevice::ReadOnly))
    {
        const QByteArray signBegin = "\n#<Host Director permanent>\n";
        const QByteArray signEnd = "\n#</Host Director permanent>\n";
        if(hostsFile.write(signBegin + confFile.readAll() + signEnd))
        {
            return;
        }
    }
    HostDirectorErrorHandler::dispatchError(Error::HOSTS_WRITE_FAILED);
}

bool HostDirectorFileWriter::eraseConfiguration()
{
    QFile hostsFile(HostConstant::HOSTS_PATH);
    // Hosts copy is already opened at this point.
    if(hostsFile.open(QIODevice::WriteOnly))
    {
        if(hostsFile.write(hostsCopy.readAll()) >= 0)
        {
            hostsCopy.remove();
            return true;
        }
    }
    HostDirectorErrorHandler::dispatchError(Error::HOSTS_CONF_ERASE_FAILED);
    return false;
}

bool HostDirectorFileWriter::isCopyExists()
{
    return QFile::exists(hostsCopy.fileName());
}

bool HostDirectorFileWriter::createHostsCopy(QFile &hostsFile)
{
    if(hostsFile.copy("temp/hosts_copy"))
    {
        // We open file to disallow user to delete it. Will be closed in eraseConfiguration.
        hostsCopy.open(QIODevice::ReadOnly | QIODevice::ExistingOnly | QIODevice::Text);
        return true;
    }
    HostDirectorErrorHandler::dispatchError(Error::HOSTS_COPY_FAILED);
    return false;
}
