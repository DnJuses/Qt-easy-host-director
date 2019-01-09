#ifndef PASSWORDNOTIFICATIONTEMPLATES_H
#define PASSWORDNOTIFICATIONTEMPLATES_H
#include "PasswordTemplateTypes.h"
#include <QObject>

class PasswordNotificationTemplates : private QObject
{
public:
    static void playTemplate(PasswordTemplate::Id templateId);
};

#endif // PASSWORDNOTIFICATIONTEMPLATES_H
