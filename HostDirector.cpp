#include "HostDirector.h"
#include "HostDirectorConstants.h"
#include "ui_HostDirector.h"
#include <QtEvents>
#include <QFileDialog>

HostDirector::HostDirector(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HostDirector),
    tray(new HostDirectorTrayMenu(this)),
    tester(new HostDirectorTestModule(this)),
    fileWriter(new HostDirectorFileWriter(this))
{
    ui->setupUi(this);
    QObject::connect(ui->startButton, &QPushButton::clicked, this, &HostDirector::startAction);
    QObject::connect(ui->browseButton, &QPushButton::clicked, this, &HostDirector::browseFile);
    QObject::connect(ui->timerLine, &TimerLineEdit::timerStopped, this, &HostDirector::undoAction);
    ui->startButton->stackUnder(this);
}

HostDirector::~HostDirector()
{
    delete ui;
}
void HostDirector::closeEvent(QCloseEvent *event)
{
    this->hide();
    event->ignore();
}

void HostDirector::browseFile()
{
    ui->pathLine->setText(QFileDialog::getOpenFileName(nullptr, nullptr, nullptr, tr("Any (*.*);;Host director configuration file (*.hdcf);;Text file (*.txt)")));
}

void HostDirector::startAction()
{
    const QString confPath = ui->pathLine->text();
    if(!tester->testPathOpenability(confPath)
    || !tester->testHostsOpenability())
    {
        return;
    }
    const bool isPermanent = ui->act_permchange->isChecked();
    if(isPermanent)
    {
        fileWriter->writePermanentConfiguration(confPath);
        return;
    }
    else
    {
        if(!fileWriter->writeConfiguration(confPath))
        {
            return;
        }
        tray->showMessage(tr("Host Director"), tr("Timer started"), QSystemTrayIcon::Information);
        ui->timerLine->startTimer(ui->intbox_hours->value(), ui->intbox_minutes->value(), ui->intbox_seconds->value());
    }
}

void HostDirector::undoAction()
{
    tray->showMessage(tr("Host Director"), tr("Timer expired"), QSystemTrayIcon::Information);
    fileWriter->eraseConfiguration();
}
