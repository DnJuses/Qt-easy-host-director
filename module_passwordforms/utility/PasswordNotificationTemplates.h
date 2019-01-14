#ifndef PASSWORDNOTIFICATIONTEMPLATES_H
#define PASSWORDNOTIFICATIONTEMPLATES_H
#include "module_passwordforms/utility/PasswordTemplateTypes.h"
#include <QObject>

class PasswordNotificationTemplates : public QObject
{
    Q_OBJECT
public:
    static void playTemplate(PasswordTemplate::Id templateId);
private:
    PasswordNotificationTemplates();
};

#endif // PASSWORDNOTIFICATIONTEMPLATES_H
