#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) : QDialog(parent), ui(new Ui::Login) {
  ui->setupUi(this);
}

Login::~Login() { delete ui; }

void Login::on_signin_button_clicked() {
  //Переводим пользователя на форму регистрации
}

void Login::on_login_button_clicked() {
  //Проверяем поля и вызываем менеджера авторизации
}
