#include "login.h"
#include "ui_login.h"
#include <QCryptographicHash>
#include <QDebug>
Login::Login(QWidget *parent) : QDialog(parent), ui(new Ui::Login) {
  ui->setupUi(this);
}

Login::~Login() { delete ui; }

void Login::on_signin_button_clicked() {
  //Переводим пользователя на форму регистрации
}

void Login::on_login_button_clicked() {
  //Проверяем поля и вызываем менеджера авторизации
    QString login = ui->login_input->text();
    QString password = ui->password_input->text();

    QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256); // Вычисляем хэш пароля
       qDebug() << "Password hash:" << passwordHash.toHex(); // Выводим хэш в шестнадцатеричном формате

}
