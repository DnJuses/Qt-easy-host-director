#ifndef CONFIGURATIONEDITOR_H
#define CONFIGURATIONEDITOR_H
#include "module_editor/customforms/MagneticWidget.h"


namespace Ui {
class ConfigurationEditor;
}

class ConfigurationEditor : public MagneticWidget
{
    Q_OBJECT

public:
    explicit ConfigurationEditor(QWidget *magnetToWidget = nullptr);
    ~ConfigurationEditor() override;

private:
    Ui::ConfigurationEditor *ui;
    QString savePath;
    void closeEvent(QCloseEvent* event) override;

private slots:
    void toConf();
    void openFile();
    void saveFile();
    void saveAsFile();
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void clear();
    void insertLh();
    void insertLhClp();

signals:
    void confReady(const QString &path);
};

#endif // CONFIGURATIONEDITOR_H
