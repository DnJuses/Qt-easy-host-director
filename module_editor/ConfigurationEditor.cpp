#include "ConfigurationEditor.h"
#include "ui_ConfigurationEditor.h"
#include <QtEvents>
#include <QMessageBox>
#include <QFileDialog>
#include <QClipboard>
#include <QDateTime>

const QString CFG_DIR = "cfgs";

ConfigurationEditor::ConfigurationEditor(QWidget *magnetToWidget) :
    MagneticWidget(magnetToWidget),
    ui(new Ui::ConfigurationEditor),
    savePath("")
{
    ui->setupUi(this);
    if(!QDir().exists(CFG_DIR))
    QDir().mkdir(CFG_DIR);
    QObject::connect(ui->useAsConf, &QPushButton::clicked, this, &ConfigurationEditor::toConf);
    QObject::connect(ui->open, &QToolButton::clicked, this, &ConfigurationEditor::openFile);
    QObject::connect(ui->save, &QToolButton::clicked, this, &ConfigurationEditor::saveFile);
    QObject::connect(ui->undo, &QToolButton::clicked, this, &ConfigurationEditor::undo);
    QObject::connect(ui->redo, &QToolButton::clicked, this, &ConfigurationEditor::redo);
    QObject::connect(ui->insertLocal, &QToolButton::clicked, this, &ConfigurationEditor::insertLh);
    QObject::connect(ui->insertLocalClipboard, &QToolButton::clicked, this, &ConfigurationEditor::insertLhClp);
    QObject::connect(ui->act_open, &QAction::triggered, this, &ConfigurationEditor::openFile);
    QObject::connect(ui->act_save, &QAction::triggered, this, &ConfigurationEditor::saveFile);
    QObject::connect(ui->act_saveAs, &QAction::triggered, this, &ConfigurationEditor::saveAsFile);
    QObject::connect(ui->act_close, &QAction::triggered, this, &ConfigurationEditor::close);
    QObject::connect(ui->act_undo, &QAction::triggered, this, &ConfigurationEditor::undo);
    QObject::connect(ui->act_redo, &QAction::triggered, this, &ConfigurationEditor::redo);
    QObject::connect(ui->act_cut, &QAction::triggered, this, &ConfigurationEditor::cut);
    QObject::connect(ui->act_copy, &QAction::triggered, this, &ConfigurationEditor::copy);
    QObject::connect(ui->act_paste, &QAction::triggered, this, &ConfigurationEditor::paste);
    QObject::connect(ui->act_clear, &QAction::triggered, this, &ConfigurationEditor::clear);
    QObject::connect(ui->act_insertLh, &QAction::triggered, this, &ConfigurationEditor::insertLh);
    QObject::connect(ui->act_insertLhClp, &QAction::triggered, this, &ConfigurationEditor::insertLhClp);
}

ConfigurationEditor::~ConfigurationEditor()
{
    delete ui;
    this->deleteLater();
}

void ConfigurationEditor::closeEvent(QCloseEvent *event)
{
    this->hide();
    event->ignore();
}

void ConfigurationEditor::toConf()
{
    this->saveFile();
    emit confReady(savePath);
}

void ConfigurationEditor::openFile()
{
    const QString openFilePath = QFileDialog::getOpenFileName(nullptr, nullptr, nullptr, tr("Text document (*.txt);;Host director configuration file (*.hdcf)"));
    if(openFilePath == savePath || openFilePath == "") return;
    QFile openedFile(openFilePath);
    if(openedFile.open(QIODevice::ReadOnly))
    {
        QByteArray fileContent = openedFile.readAll();
        ui->confEdit->setText(fileContent);
        savePath = openFilePath;
        openedFile.close();
        return;
    }
    QMessageBox cantOpen;
    cantOpen.setWindowTitle(tr("Configuration Editor"));
    cantOpen.setText(tr("Unable to open file."));
    cantOpen.setIcon(QMessageBox::Critical);
    cantOpen.exec();
}

void ConfigurationEditor::saveFile()
{
    if(savePath == "")
    {
        QMessageBox::StandardButton conf;
        conf = QMessageBox::question(nullptr,
                                     tr("Configuration Editor"),
                                     tr("Can't determine save file. Save to standard path? ('cfgs' directory)"),
                                     QMessageBox::Yes | QMessageBox::No,
                                     QMessageBox::Yes);
        if(conf == QMessageBox::Yes)
        {
            savePath = CFG_DIR + "/conf_" + QDateTime::currentDateTime().toString("dd.MM.yyyy.hh.mm.ss") + ".hdcf";
        }
        else
        {
            return;
        }
    }
    QFile saveFile(savePath);
    if(saveFile.open(QIODevice::WriteOnly))
    {
        QByteArray toSave = ui->confEdit->toPlainText().toUtf8();
        saveFile.write(toSave);
        saveFile.close();
        return;
    }
    QMessageBox cantSave;
    cantSave.setWindowTitle(tr("Configuration Editor"));
    cantSave.setText(tr("Unable to save file"));
    cantSave.setIcon(QMessageBox::Critical);
    cantSave.exec();
}

void ConfigurationEditor::saveAsFile()
{
    const QString saveFilePath = QFileDialog::getSaveFileName(nullptr, nullptr, nullptr, tr("Text document (*.txt);;Host director configuration file (*.hdcf)"));
    if(saveFilePath == "") return;
    QFile saveFile(saveFilePath);
    if(saveFile.open(QIODevice::WriteOnly))
    {
        QByteArray toSave = ui->confEdit->toPlainText().toUtf8();
        saveFile.write(toSave);
        savePath = saveFilePath;
        return;
    }
    QMessageBox cantSave;
    cantSave.setWindowTitle(tr("Configuration Editor"));
    cantSave.setText(tr("Unable to save file"));
    cantSave.setIcon(QMessageBox::Critical);
    cantSave.exec();
}

void ConfigurationEditor::undo()
{
    QTextDocument *document = ui->confEdit->document();
    if(document->isUndoAvailable())
        document->undo();
}

void ConfigurationEditor::redo()
{
    QTextDocument *document = ui->confEdit->document();
    if(document->isRedoAvailable())
    document->redo();
}

void ConfigurationEditor::cut()
{
    QApplication::clipboard()->clear(QClipboard::Clipboard);
    ui->confEdit->cut();
}

void ConfigurationEditor::copy()
{
    QApplication::clipboard()->clear(QClipboard::Clipboard);
    ui->confEdit->copy();
}

void ConfigurationEditor::paste()
{
    ui->confEdit->paste();
}

void ConfigurationEditor::clear()
{
    ui->confEdit->clear();
}

void ConfigurationEditor::insertLh()
{
    ui->confEdit->insertPlainText("127.0.0.1 ");
}

void ConfigurationEditor::insertLhClp()
{
    ui->confEdit->insertPlainText("127.0.0.1 " + QApplication::clipboard()->text(QClipboard::Clipboard) + "\n");
}
