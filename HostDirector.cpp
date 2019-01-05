#include "HostDirectorConstants.h"
#include "HostDirector.h"
#include "HostDirectorFileWriter.h"
#include "ui_HostDirector.h"
#include <QFileDialog>
#include <QDebug>

HostDirector::HostDirector(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HostDirector),
    tester(new HostDirectorTestModule(this)),
    fileWriter(new HostDirectorFileWriter(this))
{
    ui->setupUi(this);
    QObject::connect(ui->startButton, &QPushButton::clicked, this, &HostDirector::startAction);
    QObject::connect(ui->browseButton, &QPushButton::clicked, this, &HostDirector::browseFile);
    QObject::connect(ui->timerLine, &TimerLineEdit::timerStopped, this, &HostDirector::undoAction);
}

HostDirector::~HostDirector()
{
    delete ui;
}

void HostDirector::setWidgetsDisabled(bool activity)
{
    this->setDisabled(activity);
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
        ui->timerLine->startTimer(ui->intbox_hours->value(), ui->intbox_minutes->value(), ui->intbox_seconds->value());
    }
    this->setWidgetsDisabled(true);
}

void HostDirector::undoAction()
{
    fileWriter->eraseConfiguration();
    this->setWidgetsDisabled(false);
}
