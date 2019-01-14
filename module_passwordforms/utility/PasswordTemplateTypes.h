#ifndef PASSWORDTEMPLATETYPES_H
#define PASSWORDTEMPLATETYPES_H
namespace PasswordTemplate
{
    enum class Id: unsigned short
    {
        WRONG_OLD = 0,
        WRONG_CONFIRM = 1,
        EMPTY_PASSWORDS = 2,
        CREATED_SUCCESSFULLY = 3
    };
}

#endif // PASSWORDTEMPLATETYPES_H
