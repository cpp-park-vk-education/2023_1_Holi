
#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H

#include <QRegularExpression>



class User;
class MainWindow;
class RegistrationManager {
public:
  RegistrationManager() = default;
  ~RegistrationManager() = default;

  void registerUser(const QString &name, const QString &email,
                    const QString &password, MainWindow *window);

  bool validateUserDetails(const QString &name, const QString &email,
                           const QString &password);

  bool saveUserToDatabase(const QString &name, const QString &email,
                          const QString &password, MainWindow *window);

  bool isUsernameAvailable(const QString &username);

  bool isEmailValid(const QString &email);
  bool isPasswordValid(const QString &password, const QString &username,
                       const QString &email);

private:
  std::unique_ptr<User> user;

};

#include "user/user.hpp"
#include "mainwindow.h"
#endif // REGISTRATIONMANAGER_H
