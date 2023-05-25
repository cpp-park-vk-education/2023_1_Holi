
#include "registrationmanager.h"
#include <QDebug>
#include <QSettings>


/*
@brief Функция создания пользователя
@detailed Данная функция формирует обьект пользователь
@param name Имя пользователя
@param email Почта
@param password Пароль
@return Возвращает обьект user который становится текущим и записывается в базу
данных
*/
void RegistrationManager::registerUser(const QString &name,
                                       const QString &email,
                                       const QString &password, MainWindow *window) {
  //User user(name.toStdString(), email.toStdString(), password.toStdString());
  if (saveUserToDatabase(name,email,password, window)) {
  } else {
    qDebug() << "Пользователь уже существует";

  }
}

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
bool RegistrationManager::validateUserDetails(const QString &name,
                                              const QString &email,
                                              const QString &password) {
  if (isUsernameAvailable(name) && isEmailValid(email) &&
      isPasswordValid(password, name, email)) {
    return true;
  }
  return false;
}
/*
@brief Функция для охранения в БД
@detailed Данная функция сохраняет пользователя в базу данных
@param user Обьект класса пользователь
@return Возвращает true если имя уникальное, false если такой пользователь уже
есть
*/
bool RegistrationManager::saveUserToDatabase(const QString &name,
                                             const QString &email,
                                             const QString &password, MainWindow *window) {
  QSettings current("Holi", "CurrentUser");// это все его настройки
  current.setValue("user_id",0);

  user = std::make_unique<User>();
    std::cout << "SAVE";
  user->registrate(name.toStdString(), email.toStdString(),password.toStdString(), window);
  // TODO: сохранить пользователя в базу данных
  return true;
}

/*
@brief Функция для проверки корректности имени пользователя
@detailed Данная функция проверяет есть ли в базе такой же username
@param name Имя пользователя
@return Возвращает true если имя уникальное, false если такой пользователь уже
есть
*/
bool RegistrationManager::isUsernameAvailable(const QString &username) {
  // TODO: проверить есть ли в базе пользователь с таким именем
  return true;
}

/*
@brief Функция для проверки корректности почты
@detailed Данная функция проверяет соответствует ли строка формату почты
@param email Почта
@return Возвращает true если соответствует, иначе false
*/
bool RegistrationManager::isEmailValid(const QString &email) {
  QRegularExpression pattern("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}");
  QRegularExpressionMatch match = pattern.match(email);
  return match.hasMatch();
}

/*
@brief Функция для проверки корректности пароля
@detailed Данная функция проверяет пароль
@param name Имя пользователя
@param email Почта
@param password Пароль
@return Возвращает true если соответствует, иначе false
*/
bool RegistrationManager::isPasswordValid(const QString &password,
                                          const QString &username,
                                          const QString &email) {
  // Проверка на заглавную букву
  QRegularExpression uppercaseRegex("[A-Z]");
  if (!uppercaseRegex.match(password).hasMatch()) {
    qDebug() << "1 отсутствует заглавная буква";
    return false;
  }

  // Проверка на строчную букву
  QRegularExpression lowercaseRegex("[a-z]");
  if (!lowercaseRegex.match(password).hasMatch()) {
    qDebug() << "2 отсутствует строчная буква";
    return false;
  }

  // Проверка на специальный символ
  QRegularExpression specialCharRegex("[^\\w\\s]");
  if (!specialCharRegex.match(password).hasMatch()) {
    qDebug() << "3 отсутствует специальный символ";
    return false;
  }

  // Проверка на числа
  QRegularExpression digitRegex("\\d");
  if (!digitRegex.match(password).hasMatch()) {
    qDebug() << "4 отсутствует число";
    return false;
  }

  // Провека на повторение имени пользователя или почты в пароле
  QRegularExpression usernameRegex(username);
  QRegularExpression emailRegex(email);
  if (usernameRegex.match(password).hasMatch() ||
      emailRegex.match(password).hasMatch()) {
    qDebug() << "5 дублирование почты и/или имени пользователя";
    return false;
  }

  // Проверка на длину пароля
  if (password.length() < 8) {
    qDebug() << "6 длина меньше 8";
    return false;
  }

  qDebug() << "Пароль корректный";
  return true;
}
