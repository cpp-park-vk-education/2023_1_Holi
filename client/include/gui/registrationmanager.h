
#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H

#include <QRegularExpression>

#include "user/user.hpp"

class RegistrationManager {
public:
  RegistrationManager();
  /*
@brief Функция создания пользователя
@detailed Данная функция формирует обьект пользователь
@param name Имя пользователя
@param email Почта
@param password Пароль
@return Возвращает обьект user который становится текущим и записывается в базу
данных
*/
  User registerUser(const QString &name, const QString &email,
                    const QString &password);
  /*
@brief Функция для проверки корректности полей при создании пользователя
@detailed Данная функция проверяет почту на присутствие символа @ и пароль на
длину, регистры и символы
@param name Имя пользователя
@param email Почта
@param password Пароль
@return Возвращает true or false в зависимости от того, соответствуют ли данные
регистрации требованиям к безопасности
*/
  bool validateUserDetails(const QString &name, const QString &email,
                           const QString &password);

  bool saveUserToDatabase(const User &user);
  /*
@brief Функция для проверки корректности имени пользователя
@detailed Данная функция проверяет есть ли в базе такой же username
@param name Имя пользователя
@return Возвращает true если имя уникальное, false если такой пользователь уже
есть
*/
  bool isUsernameAvailable(const QString &username);
  /*
@brief Функция для проверки корректности почты
@detailed Данная функция проверяет соответствует ли строка формату почты
@param email Почта
@return Возвращает true если соответствует, иначе false
*/
  bool isEmailValid(const QString &email);
  bool isPasswordValid(const QString &password, const QString &username,
                       const QString &email);
};


#endif // REGISTRATIONMANAGER_H
