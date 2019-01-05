#ifndef HOSTDIRECTOR_H
#define HOSTDIRECTOR_H

#include <QMainWindow>
#include <QFile>
#include <QString>
#include "HostDirectorFileWriter.h"
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
private:
    Ui::HostDirector *ui;
    HostDirectorTestModule *tester;
    HostDirectorFileWriter *fileWriter;
    void setWidgetsDisabled(bool active);
private slots:
    void browseFile();
    void startAction();
    void undoAction();
};

#endif // HOSTDIRECTOR_H
