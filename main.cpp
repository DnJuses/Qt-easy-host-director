#include "module_hostdirector/HostDirector.h"
#include "module_hostdirector/utility/HostDirectorFileWriter.h"
#include "module_hostdirector/utility/HostDirectorErrorHandler.h"
#include "module_passwordforms/confirmationform/PasswordConfirmationForm.h"
#include "module_passwordforms/creationform/PasswordCreationForm.h"
#include "module_editor/ConfigurationEditor.h"
#include <QApplication>
#include <QtCore>
#include <QMessageBox>
#include <QDebug>

#ifdef QT_DEBUG
    #define STD_TR_NAME ""
    #define STD_QT_TR_NAME ""
#else
    #define STD_TR_NAME "hdir_"
    #define STD_QT_TR_NAME "qt_"
#endif

bool singleApp()
{
    QSystemSemaphore singleApp("<uniq id>", 1);
    singleApp.acquire();
#ifndef Q_OS_WIN32 // Освободить память при аварийном закрытии программы в Linux
    QSharedMemory unixFixLeak("<uniq id 2>");
    if(unixFixLeak.attach())
        unixFixLeak.detach();
#endif
    QSharedMemory AppSM("<uniq id 2>");
    bool appIsRunning = false;

    if(AppSM.attach())
    {
        appIsRunning = true;
    }
    else
    {
        AppSM.create(1);
        appIsRunning = false;
    }

    singleApp.release();
    return appIsRunning;
}

int main(int argc, char *argv[])
{
    if(singleApp())
    {
        HostDirectorErrorHandler::dispatchError(ErrorTypes::ErrorValue::APP_ALREADY_RUNNING);
        return 0;
    }
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Suvo softworks");
    QCoreApplication::setApplicationName("Host Director");
    QTranslator languageTranslator;
    QTranslator qtTranslator;
    HostDirector w;
    if(languageTranslator.load(STD_TR_NAME + QLocale::system().name(), "translations")
    && qtTranslator.load(STD_QT_TR_NAME + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
    {
         app.installTranslator(&languageTranslator);
         app.installTranslator(&qtTranslator);
    }
    if(!AbstractPasswordForm::isPasswordExists())
    {
        QMessageBox::StandardButton confirm;
        confirm = QMessageBox::question(nullptr,
                                        QApplication::tr("Password Manager"),
                                        QApplication::tr("It seems like you don't have any passwords with you. Want to create one?"),
                                        QMessageBox::Yes | QMessageBox::No,
                                        QMessageBox::Yes);
        if(confirm == QMessageBox::Yes)
        {
            PasswordCreationForm create;
            create.exec();
        }
    }
    if(HostDirectorFileWriter::isCopyExists())
    {
        QMessageBox::StandardButton confirm;
        confirm = QMessageBox::question(nullptr,
                                        QApplication::tr("Host Director"),
                                        QApplication::tr("The application was closed in wrong way and changes still in effect. To undo them, press 'Ok' and type in your password."),
                                        QMessageBox::Yes | QMessageBox::No,
                                        QMessageBox::Yes);
        if(confirm == QMessageBox::Yes)
        {
            if(AbstractPasswordForm::isPasswordExists())
            {
                PasswordConfirmationForm confirmForm;
                confirmForm.exec();
                if(confirmForm.isCorrect())
                {
                    HostDirectorFileWriter::eraseConfigurationUnpair();
                }
            }
            else
            {
                HostDirectorFileWriter::eraseConfigurationUnpair();
            }
        }
    }
    w.show();
    return app.exec();
}
