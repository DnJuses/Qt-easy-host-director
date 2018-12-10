#include "HostDirector.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HostDirector w;
    w.show();
    return a.exec();
}
