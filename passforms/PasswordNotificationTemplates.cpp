#include "PasswordNotificationTemplates.h"
#include <QMessageBox>
#include <QPixmap>
typedef PasswordTemplate::Id Template;
void PasswordNotificationTemplates::playTemplate(Template templateId)
{
    QMessageBox notification;
    const QString title = tr("Password Manager");
    QString message = "";
    QMessageBox::Icon stdIcon = QMessageBox::NoIcon;
    QPixmap customIcon;
    switch(templateId)
    {
        case Template::WRONG_OLD:
            message = tr("Old password is incorrect!");
            stdIcon = QMessageBox::Critical;
        break;
        case Template::WRONG_CONFIRM:
            message = tr("Confirm password is incorrect!");
            stdIcon = QMessageBox::Critical;
        break;
        case Template::EMPTY_PASSWORDS:
            message = tr("Password lines is empty. No password will be used. You can change it later by clicking 'Change password' action in tray-menu");
            stdIcon = QMessageBox::Information;
        break;
        case Template::CREATED_SUCCESSFULLY:
            message = tr("Password created successfully");
            customIcon = QPixmap(":images/icons/tick.ico");
        break;
    }
    notification.setWindowTitle(title);
    notification.setText(message);
    stdIcon == QMessageBox::NoIcon ? notification.setIconPixmap(customIcon) : notification.setIcon(stdIcon);
    notification.show();
    notification.exec();
}
