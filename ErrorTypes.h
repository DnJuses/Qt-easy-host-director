#ifndef ERRORTYPES_H
#define ERRORTYPES_H

// Error are sent by HostDirectorTestModule, handled by HostDirectorErrorHandler
// Host director errors diapason 2000-2999.
namespace ErrorTypes
{
    enum class ErrorValue: unsigned short
    {
        WRONG_CONF_FILE_PATH = 2000,
        HOSTS_ACCESS_DENIED = 2001
    };
}

#endif // ERRORTYPES_H
