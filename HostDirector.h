#ifndef HOSTDIRECTOR_H
#define HOSTDIRECTOR_H

#include <QMainWindow>
#include "HostDirectorErrorHandler.h"
#include "HostDirectorTestModule.h"
#include "ErrorTypes.h"

namespace Ui {
class HostDirector;
}

class HostDirector : public QMainWindow
{
    Q_OBJECT

public:
    explicit HostDirector(QWidget *parent = nullptr);
    ~HostDirector();

signals:
    void handleError(ErrorTypes::ErrorValue);
private:
    Ui::HostDirector *ui;
    HostDirectorTestModule *tester;
    HostDirectorErrorHandler *errorHandler;
private slots:
    void browseFile();
    void startAction();
};

#endif // HOSTDIRECTOR_H
