#ifndef HOSTDIRECTOR_H
#define HOSTDIRECTOR_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include "HostDirectorTrayMenu.h"
#include "HostDirectorFileWriter.h"
#include "HostDirectorTestModule.h"

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
    HostDirectorTrayMenu *tray;
    HostDirectorTestModule *tester;
    HostDirectorFileWriter *fileWriter;
    void setWidgetsDisabled(bool active);
    void closeEvent(QCloseEvent* event) override;
private slots:
    void browseFile();
    void startAction();
    void undoAction();
};

#endif // HOSTDIRECTOR_H
