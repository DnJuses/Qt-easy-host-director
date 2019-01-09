#ifndef ERRORTYPES_H
#define ERRORTYPES_H

// Error are sent by HostDirectorTestModule, handled by HostDirectorErrorHandler
// Host director errors diapason 2000-2999.
namespace ErrorTypes
{
    enum class ErrorValue: unsigned short
    {
        WRONG_CONF_FILE_PATH = 2000,
        HOSTS_ACCESS_DENIED = 2001,
        CONFIGURATION_ACCESS_DENIED = 2002,
        HOSTS_COPY_FAILED = 2003,
        HOSTS_CONF_ERASE_FAILED = 2004,
        HOSTS_WRITE_FAILED = 2005,
        APP_ALREADY_RUNNING = 2006
    };
}

#endif // ERRORTYPES_H
