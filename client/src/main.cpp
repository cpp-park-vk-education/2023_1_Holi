//
// Created by Алексей on 01.05.2023.
//


#include <iostream>

#include "mainwindow.h"
#include "registrationmanager.h"
#include <QApplication>

//#include "client/request_maker_tmp.h"
//#include "client/https_request_maker_tmp.h"


int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  MainWindow w;

  RegistrationManager r;
  QString email = "user@user.com";
  if (r.isEmailValid(email)) {
    qDebug() << "YES email"
             << "\n";
  } else {
    qDebug() << "NO"
             << "\n";
  }



  QString pas1 = "et45hjdtj@$grsgFFF!";
  QString pas2 = "1234";
  QString pas3 = "user";

  QString username = "user";

  if (r.isPasswordValid(pas1, username, email)) {
    qDebug() << "YES pas1"
             << "\n";
  } else {
    qDebug() << "NO pas1"
             << "\n";
  }

  if (r.isPasswordValid(pas2, username, email)) {
    qDebug() << "YES pas2"
             << "\n";
  } else {
    qDebug() << "NO pas2"
             << "\n";
  }

  if (r.isPasswordValid(pas3, username, email)) {
    qDebug() << "YES pas3"
             << "\n";
  } else {
    qDebug() << "NO pas3"
             << "\n";
  }

  w.show();

  return a.exec();
}




