
#ifndef AUTHENTICATIONMANAGER_H
#define AUTHENTICATIONMANAGER_H
#include <QCryptographicHash>
#include <QString>


class AuthenticationManager
{
public:
    AuthenticationManager();

    bool authenticateUser(const QString& login, const QString& password);

    bool authorizeUser(const QString& userID);

    bool logoutUser(const QString& userID);

    QString makeHash(const QString& str);
};

#endif // AUTHENTICATIONMANAGER_H
