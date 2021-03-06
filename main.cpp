#include "module_hostdirector/HostDirector.h"
#include "module_hostdirector/utility/HostDirectorFileWriter.h"
#include "module_hostdirector/utility/HostDirectorErrorHandler.h"
#include "module_passwordforms/confirmationform/PasswordConfirmationForm.h"
#include "module_passwordforms/creationform/PasswordCreationForm.h"
#include <QApplication>
#include <QtCore>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Suvo softworks");
    QCoreApplication::setApplicationName("Host Director");
    QTranslator languageTranslator;
    QTranslator qtTranslator;
    if(languageTranslator.load("hdir_" + QLocale::system().name(), "translations")
    && qtTranslator.load("qt_" + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
    {
         app.installTranslator(&languageTranslator);
         app.installTranslator(&qtTranslator);
    }
    QSystemSemaphore singleApp("<uniq id>", 1);
    singleApp.acquire();
#ifndef Q_OS_WIN32
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
    if(appIsRunning)
    {
        HostDirectorErrorHandler::dispatchError(ErrorTypes::ErrorValue::APP_ALREADY_RUNNING);
        return 0;
    }
    if(!AbstractPasswordForm::isPasswordExists())
    {
        QMessageBox::StandardButton confirm;
        confirm = QMessageBox::question(nullptr,
                                        QApplication::tr("Password manager"),
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
                                        QApplication::tr("Host director"),
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
    HostDirector w;
    w.show();
    return app.exec();
}
