#ifndef HOSTCONSTANTS_H
#define HOSTCONSTANTS_H
#include <QString>

namespace HostConstant{
    static const QString HOSTS_PATH = QString::fromLocal8Bit(qgetenv("windir")) + QString("\\System32\\drivers\\etc\\hosts");
    static const QString PASSWORD_REGISTRY_KEY = "hash";
    static const quint16 XOR_KEY = 27;
};

#endif // HOSTCONSTANTS_H
