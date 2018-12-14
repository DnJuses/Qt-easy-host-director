#include "HostDirector.h"
#include "ui_HostDirector.h"
#include <QFileDialog>
#include <QDebug>

extern const QString HOSTS_PATH;
static QFile HOSTS_FILE(HOSTS_PATH);

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

bool HostDirector::writeConfiguration(const QString &confPath)
{
    return true;
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
    if(!writeConfiguration(confPath))
    {
        return;
    }
}
