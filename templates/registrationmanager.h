
#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H

#include "user.h"


class RegistrationManager
{
public:
    RegistrationManager();

    User registerUser(const QString& name, const QString& email, const QString& password);

    bool validateUserDetails(const User& user);

    bool saveUserToDatabase(const User& user);
};

#endif // REGISTRATIONMANAGER_H
