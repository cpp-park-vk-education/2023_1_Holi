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

  w.show();

  return a.exec();
}




