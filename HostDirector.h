#ifndef HOSTDIRECTOR_H
#define HOSTDIRECTOR_H

#include <QMainWindow>

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
};

#endif // HOSTDIRECTOR_H
