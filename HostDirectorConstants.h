#ifndef HOSTCONSTANTS_H
#define HOSTCONSTANTS_H
#include <QString>

namespace HostConstant{
    static const QString HOSTS_PATH = QString::fromLocal8Bit(qgetenv("windir")) + QString("\\System32\\drivers\\etc\\hosts");
};

#endif // HOSTCONSTANTS_H
