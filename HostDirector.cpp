#include "HostDirector.h"
#include "ui_HostDirector.h"
#include <QFileDialog>
#include <QDebug>
extern const QString HOSTS_PATH;

HostDirector::HostDirector(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HostDirector)
{
    ui->setupUi(this);
    tester = new HostDirectorTestModule(this);
    errorHandler = new HostDirectorErrorHandler(this);
    QObject::connect(tester, &HostDirectorTestModule::handleError, errorHandler, &HostDirectorErrorHandler::dispatchError);
    QObject::connect(ui->startButton, &QPushButton::clicked, this, &HostDirector::startAction);
    QObject::connect(ui->browseButton, &QPushButton::clicked, this, &HostDirector::browseFile);
}

HostDirector::~HostDirector()
{
    delete ui;
}

void HostDirector::browseFile()
{
    ui->pathLine->setText(QFileDialog::getOpenFileName(nullptr, nullptr, nullptr, tr("Any (*.*);;Host director configuration file (*.hdcf);;Text file (*.txt)")));
}

void HostDirector::startAction()
{
    if(!tester->testPath(ui->pathLine->text())
    || !tester->testHostsOpenability())
    {
        return;
    }
}
