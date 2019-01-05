#ifndef TRAYMENU_H
#define TRAYMENU_H

#include <QMenu>
#include <QSystemTrayIcon>

class HostDirectorTrayMenu : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit HostDirectorTrayMenu(QWidget *parent = nullptr);
    ~HostDirectorTrayMenu();
private:
    QMenu *actMenu;
    QAction *act_hide;
    QAction *act_restore;
    QAction *act_recreatePass;
    QAction *act_quit;
private slots:
    void recreatePassword();
    void iconTriggered(QSystemTrayIcon::ActivationReason reason);
};

#endif // TRAYMENU_H
