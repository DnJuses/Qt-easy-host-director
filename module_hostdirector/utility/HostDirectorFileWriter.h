#ifndef HOSTFILEWRITER_H
#define HOSTFILEWRITER_H

#include <QObject>
#include <QFile>

class HostDirectorFileWriter : public QObject
{
    Q_OBJECT
public:
    explicit HostDirectorFileWriter(QObject *parent = nullptr);
    static bool isCopyExists();
    bool writeConfiguration(const QString &confPath); // Must be used in pair with eraseConfiguration();
    void writePermanentConfiguration(const QString &confPath);
    bool eraseConfiguration();
    static bool eraseConfigurationUnpair();
private:
    bool createHostsCopy(QFile &hostsFile);
    static QFile hostsCopy;
};

#endif // HOSTFILEWRITER_H
