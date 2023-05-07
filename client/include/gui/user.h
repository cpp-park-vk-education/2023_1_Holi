
#ifndef USER_H
#define USER_H


#include <QString>

class User
{
public:
    User(const QString& login, const QString& email, const QString& password);

    QString getLogin() const;
    void setLogin(const QString& login);

    QString getEmail() const;
    void setEmail(const QString& email);

    QString getPassword() const;
    void setPassword(const QString& password);

    bool operator==(const User& other) const;
private:
    QString m_login;
    QString m_email;
    QString m_password;
};



#endif // USER_H
