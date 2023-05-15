#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog {
  Q_OBJECT

public:
  explicit Login(QWidget *parent = nullptr);
  ~Login();

private slots:
  void on_signin_button_clicked();

  void on_login_button_clicked();

private:
  Ui::Login *ui;
};

#endif // LOGIN_H
