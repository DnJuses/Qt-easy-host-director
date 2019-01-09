#include "passforms/PasswordRecreationForm.h"
#include "passforms/PasswordCreationForm.h"
#include "passforms/PasswordConfirmationForm.h"
#include "HostDirectorTrayMenu.h"
#include <QCommonStyle>
#include <QApplication>

HostDirectorTrayMenu::HostDirectorTrayMenu(QWidget *parent) :
    QSystemTrayIcon (parent),
    actMenu(new QMenu)
{
    this->setIcon(QIcon(":images/icons/desktopicon.ico"));

    // Hide parent window
    act_hide = new QAction(tr("Hide"), this);
    act_hide->setIcon(QCommonStyle().standardIcon(QStyle::SP_TitleBarMinButton));
    QObject::connect(act_hide, &QAction::triggered, parent, &QWidget::hide);

    // Restore parent window
    act_restore = new QAction(tr("Restore"), this);
    act_restore->setIcon(QCommonStyle().standardIcon(QStyle::SP_TitleBarMaxButton));
    QObject::connect(act_restore, &QAction::triggered, parent, &QWidget::show);

    // Recreate password
    act_recreatePass = new QAction(tr("Change password"), this);
    act_recreatePass->setIcon(QCommonStyle().standardIcon(QStyle::SP_BrowserReload));
    QObject::connect(act_recreatePass, &QAction::triggered, this, &HostDirectorTrayMenu::recreatePassword);

    // Close application
    act_quit = new QAction(tr("Quit"), this);
    act_quit->setIcon(QCommonStyle().standardIcon(QStyle::SP_TitleBarCloseButton));
    QObject::connect(act_quit, &QAction::triggered, QApplication::instance(), &QApplication::quit);

    QObject::connect(this, &QSystemTrayIcon::activated, this, &HostDirectorTrayMenu::iconTriggered);

    actMenu->addAction(act_hide);
    actMenu->addAction(act_restore);
    actMenu->addSeparator();
    actMenu->addAction(act_recreatePass);
    actMenu->addSeparator();
    actMenu->addAction(act_quit);
    this->setContextMenu(actMenu);

    this->show();
}

HostDirectorTrayMenu::~HostDirectorTrayMenu()
{
    delete actMenu;
    this->deleteLater();
}

void HostDirectorTrayMenu::recreatePassword()
{
    if(!AbstractPasswordForm::isPasswordExists())
    {
        PasswordCreationForm creationForm;
        creationForm.exec();
    }
    else
    {
        PasswordRecreationForm recreationForm;
        recreationForm.exec();
    }
}

void HostDirectorTrayMenu::iconTriggered(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
        case QSystemTrayIcon::ActivationReason::Trigger:
            qobject_cast<QWidget*>(parent())->isHidden() ? act_restore->trigger() : act_hide->trigger();
        break;
    default:
        break;
    }
}
