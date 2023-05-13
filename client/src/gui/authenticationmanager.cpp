
#include "authenticationmanager.h"

AuthenticationManager::AuthenticationManager() {}

bool AuthenticationManager::authenticateUser(const QString &login,
                                             const QString &password) {
  // TODO: запрос к БД если найден то true и записываем сользователя в Current
  // User
  return true;
}

bool AuthenticationManager::authorizeUser(const QString &userID) {
  // TODO: Даем пользователю доступ к приложению
  return true;
}

bool AuthenticationManager::logoutUser(const QString &userID) {
  // TODO: Запрещаем доступ к приложению и очищаем поля current user
}
