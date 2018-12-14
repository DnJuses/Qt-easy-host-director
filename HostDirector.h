#ifndef HOSTDIRECTOR_H
#define HOSTDIRECTOR_H

#include <QMainWindow>
#include <QFile>
#include <QString>
#include "HostDirectorErrorHandler.h"
#include "HostDirectorTestModule.h"
#include "ErrorTypes.h"


namespace Ui {
class HostDirector;
}

class HostDirector : public QMainWindow
{
    Q_OBJECT
private:
    Ui::HostDirector *ui;
    HostDirectorTestModule *tester;
    HostDirectorErrorHandler *errorHandler;
    bool writeConfiguration(const QString &confPath);
private slots:
    void browseFile();
    void startAction();

public:
    explicit HostDirector(QWidget *parent = nullptr);
    ~HostDirector();

signals:
    void handleError(ErrorTypes::ErrorValue);
};

#endif // HOSTDIRECTOR_H
