#include "HostDirector.h"
#include "ui_HostDirector.h"

HostDirector::HostDirector(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HostDirector)
{
    ui->setupUi(this);
}

HostDirector::~HostDirector()
{
    delete ui;
}
