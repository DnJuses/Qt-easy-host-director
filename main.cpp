#include "HostDirector.h"
#include <QApplication>
#include "HostDirectorFileWriter.h"
#include <QtCore>
#include <QDebug>

#ifdef QT_DEBUG
    #define STD_TR_NAME ""
    #define STD_QT_TR_NAME ""
#else
    #define STD_TR_NAME "hdir_"
    #define STD_QT_TR_NAME "qt_"
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTranslator languageTranslator;
    QTranslator qtTranslator;
    if(languageTranslator.load(STD_TR_NAME + QLocale::system().name(), "translations")
    && qtTranslator.load(STD_QT_TR_NAME + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
    {
         app.installTranslator(&languageTranslator);
         app.installTranslator(&qtTranslator);
    }
    HostDirectorFileWriter s;
    HostDirector w;
    w.show();
    return app.exec();
}
