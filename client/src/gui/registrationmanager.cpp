
#include "registrationmanager.h"

RegistrationManager::RegistrationManager()
{

}

User registerUser(const QString& name, const QString& email, const QString& password){
    User user("", "", "");

    return user;
}

bool validateUserDetails(const User& user){
    return false;
}

bool saveUserToDatabase(const User& user){
    return false;
}

