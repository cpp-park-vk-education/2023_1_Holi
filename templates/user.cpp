
#include "user.h"


User::User(const QString& login, const QString& email, const QString& password)
    : m_login(login)
    , m_email(email)
    , m_password(password)
{
}

QString User::getLogin() const
{
    return m_login;
}

void User::setLogin(const QString& login)
{
    m_login = login;
}

QString User::getEmail() const
{
    return m_email;
}

void User::setEmail(const QString& email)
{
    m_email = email;
}

QString User::getPassword() const
{
    return m_password;
}

void User::setPassword(const QString& password)
{
    m_password = password;
}

bool User::operator==(const User& other) const
{
    return m_login == other.m_login &&
           m_email == other.m_email &&
           m_password == other.m_password;
}
