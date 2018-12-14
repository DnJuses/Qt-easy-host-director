#include "HostDirector.h"
#include <QApplication>
#include <QtCore>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTranslator languageTranslator;
    QTranslator qtTranslator;
    if(languageTranslator.load("hdir_" + QLocale::system().name(), "translations")
    && qtTranslator.load("qt_" + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
    {
         app.installTranslator(&languageTranslator);
         app.installTranslator(&qtTranslator);
    }
    HostDirector w;
    w.show();
    return app.exec();
}
