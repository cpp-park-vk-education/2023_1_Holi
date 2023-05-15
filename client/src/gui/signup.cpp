#include "signup.h"
#include "registrationmanager.h"
#include "ui_signup.h"

#include <QMessageBox>

SignUp::SignUp(QWidget *parent) : QDialog(parent), ui(new Ui::SignUp) {
  ui->setupUi(this);
}

SignUp::~SignUp() { delete ui; }

void SignUp::on_signin_button_clicked() {
  //Создаем менеджер регистрации
  RegistrationManager reg;

  //Получаем данные формы
  QString username = ui->signin_input->text();
  QString email = ui->signin_input_2->text();
  QString password = ui->password_input->text();

  QString username_valid;
  if (reg.isUsernameAvailable(username)) {
    username_valid = "Допустимо";
  } else {
    username_valid = "Недопустимое имя пользователя";
  }

  QString password_valid;
  if (reg.isPasswordValid(password, username, email)) {
    password_valid = "+";
  } else {
    password_valid = "-";
  }

  QString email_valid;
  if (reg.isEmailValid(email)) {
    email_valid = "+";
  } else {
    email_valid = "-";
  }
  if (username.isEmpty() && email.isEmpty() && password.isEmpty()) {
    QMessageBox msgBox;
    msgBox.setText("Не все поля заполнены");
    msgBox.exec();
  }

  bool state = reg.validateUserDetails(username, email, password);

  if (state) {
    // TODO: Регистрируем пользователя и перенаправляем на приложение
    //Или на форму авторизации
  } else {
    QMessageBox msgBox;
    QString er = tr("Некорректно подобраны логин, почта или пароль\nИмя "
                    "пользователя: %1\nEmail: %2\nПароль: %3")
                     .arg(username_valid, email_valid, password_valid);
    msgBox.setText(er);
    msgBox.exec();
  }
}
