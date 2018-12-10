#ifndef ERRORTYPES_H
#define ERRORTYPES_H

// Error are sent by HostDirectorTestModule, handled by HostDirectorErrorHandler
namespace ErrorTypes
{
    enum class ErrorValue: int
    {
        WRONG_CONF_FILE_PATH = 201,
        HOSTS_ACCESS_DENIED = 202
    };
}

#endif // ERRORTYPES_H
