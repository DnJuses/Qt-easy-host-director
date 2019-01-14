#-------------------------------------------------
#
# Project created by QtCreator 2018-12-09T20:46:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HostDirector
TEMPLATE = app
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
RC_FILE += manifests/adminmanifest.rc
CONFIG += c++11


SOURCES += \
        main.cpp \
        module_hostdirector/HostDirector.cpp \
        module_hostdirector/customforms/TimerLineEdit.cpp \
        module_hostdirector/customforms/HostDirectorTrayMenu.cpp \
        module_hostdirector/utility/HostDirectorTestModule.cpp \
        module_hostdirector/utility/HostDirectorErrorHandler.cpp \
        module_hostdirector/utility/HostDirectorFileWriter.cpp \
        module_passwordforms/AbstractPasswordForm.cpp \
        module_passwordforms/confirmationform/PasswordConfirmationForm.cpp \
        module_passwordforms/creationform/PasswordCreationForm.cpp \
        module_passwordforms/recreationform/PasswordRecreationForm.cpp \
        module_passwordforms/utility/PasswordNotificationTemplates.cpp \
        module_editor/customforms/MagneticWidget.cpp \
        module_editor/ConfigurationEditor.cpp

HEADERS += \
        module_hostdirector/HostDirector.h \
        module_hostdirector/customforms/TimerLineEdit.h \
        module_hostdirector/customforms/HostDirectorTrayMenu.h \
        module_hostdirector/utility/ErrorTypes.h \
        module_hostdirector/utility/HostDirectorTestModule.h \
        module_hostdirector/utility/HostDirectorErrorHandler.h \
        module_hostdirector/utility/HostDirectorFileWriter.h \
        module_hostdirector/utility/HostDirectorConstants.h \
        module_passwordforms/AbstractPasswordForm.h \
        module_passwordforms/confirmationform/PasswordConfirmationForm.h \
        module_passwordforms/creationform/PasswordCreationForm.h \
        module_passwordforms/recreationform/PasswordRecreationForm.h \
        module_passwordforms/utility/PasswordNotificationTemplates.h \
        module_passwordforms/utility/PasswordTemplateTypes.h \
        module_editor/customforms/MagneticWidget.h \
        module_editor/ConfigurationEditor.h

FORMS += \
        module_hostdirector/HostDirector.ui \
        module_passwordforms/confirmationform/PasswordConfirmationForm.ui \
        module_passwordforms/creationform/PasswordCreationForm.ui \
        module_passwordforms/recreationform/PasswordRecreationForm.ui \
        module_editor/ConfigurationEditor.ui

DISTFILES += \
        manifests/adminmanifest.rc \
        manifests/admin.xml

RESOURCES += \
        resourses.qrc

TRANSLATIONS += \
        translations/hdir_ru.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

