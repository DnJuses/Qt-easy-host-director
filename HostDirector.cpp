#include "HostDirector.h"
#include "HostDirectorTestModule.h"
#include "ui_HostDirector.h"
#include <QFileDialog>
#include <QDebug>
extern const QString HOSTS_PATH;

HostDirector::HostDirector(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HostDirector)
{
    // Setting up text for translation;
this->tr("ss");

    ui->setupUi(this);

    // Setting up translation environment
    ui->tips_hours->setText(QLabel::tr("Hours"));
    ui->tips_minutes->setText(QLabel::tr("Minutes"));
    ui->tips_seconds->setText(QLabel::tr("Seconds"));
    ui->pathLine->setPlaceholderText(QLineEdit::tr("Path to the configurations file"));
    ui->startButton->setText(QPushButton::tr("Start"));
    ui->browseButton->setText(QPushButton::tr("Browse"));
    ui->act_permchange->setText(QAction::tr("Permanent change"));
    ui->menu_settings->setTitle(QMenu::tr("Settings"));

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
