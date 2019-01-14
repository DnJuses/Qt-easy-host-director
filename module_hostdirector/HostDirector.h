#ifndef HOSTDIRECTOR_H
#define HOSTDIRECTOR_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include "module_editor/ConfigurationEditor.h"
#include "module_hostdirector/customforms/HostDirectorTrayMenu.h"
#include "module_hostdirector/utility/HostDirectorFileWriter.h"
#include "module_hostdirector/utility/HostDirectorTestModule.h"

namespace Ui {
class HostDirector;
}

class HostDirector : public QMainWindow
{
    Q_OBJECT
public:
    explicit HostDirector(QWidget *parent = nullptr);
    ~HostDirector() override;
private:
    Ui::HostDirector *ui;
    ConfigurationEditor *editor;
    HostDirectorTrayMenu *tray;
    HostDirectorTestModule *tester;
    HostDirectorFileWriter *fileWriter;
    void closeEvent(QCloseEvent *event) override;
    void moveEvent(QMoveEvent *event) override;
private slots:
    void browseFile();
    void startAction();
    void undoAction();
    void passwordCheck();
};

#endif // HOSTDIRECTOR_H
