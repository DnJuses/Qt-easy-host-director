#include "module_hostdirector/HostDirector.h"
#include "module_hostdirector/utility/HostDirectorConstants.h"
#include "module_passwordforms/confirmationform/PasswordConfirmationForm.h"
#include "ui_HostDirector.h"
#include <QtEvents>
#include <QFileDialog>

HostDirector::HostDirector(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HostDirector),
    editor(new ConfigurationEditor(this)),
    tray(new HostDirectorTrayMenu(this)),
    tester(new HostDirectorTestModule(this)),
    fileWriter(new HostDirectorFileWriter(this))
{
    ui->setupUi(this);
    ui->stopButton->hide();
    QObject::connect(ui->startButton, &QPushButton::clicked, this, &HostDirector::startAction);
    QObject::connect(ui->stopButton, &QPushButton::clicked, this, &HostDirector::passwordCheck);
    QObject::connect(ui->browseButton, &QPushButton::clicked, this, &HostDirector::browseFile);
    QObject::connect(ui->timerLine, &TimerLineEdit::timerStopped, this, &HostDirector::undoAction);
    QObject::connect(ui->act_showEditor, &QAction::triggered, editor, &ConfigurationEditor::show);
    QObject::connect(editor, &ConfigurationEditor::confReady, ui->pathLine, &QLineEdit::setText);
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

void HostDirector::moveEvent(QMoveEvent *event)
{
    if(editor->isMagnetic())
    {
        QPoint ceditPos = event->oldPos() - event->pos();
        editor->move(editor->x() - ceditPos.x(), editor->y() - ceditPos.y());
    }
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
        ui->startButton->hide();
        ui->stopButton->show();
    }
}

void HostDirector::undoAction()
{
    tray->showMessage(tr("Host Director"), tr("Timer expired"), QSystemTrayIcon::Information);
    fileWriter->eraseConfiguration();
    ui->startButton->show();
    ui->stopButton->hide();
}

void HostDirector::passwordCheck()
{
    if(AbstractPasswordForm::isPasswordExists())
    {
        PasswordConfirmationForm confirmForm;
        confirmForm.exec();
        if(!confirmForm.isCorrect())
        {
            return;
        }
    }
    ui->timerLine->stopTimer();
}
