#include "mainwindow.h"
#include "ui_mainwindow.h"
/*#include "templates/main_page.h"
#include "templates/chat.h"
#include "templates/albums.h"
#include "templates/onvk.h"
#include "templates/onyoutube.h"
#include "templates/config.h"
#include "templates/login.h"
#include "templates/signup.h"
#include "templates/friends.h"
#include "templates/friends_in.h"
#include "templates/friends_out.h"*/

#include "main_page.h"
#include "chat.h"
#include "albums.h"
#include "onvk.h"
#include "onyoutube.h"
#include "config.h"
#include "login.h"
#include "signup.h"
#include "friends.h"
#include "friends_in.h"
#include "friends_out.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Имя Пользователя");
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*БОКОВОЕ МЕНЮ*/
void MainWindow::on_main_button_clicked()
{
    Main_page* main = new Main_page(this);
    ui->stackedWidget->addWidget(main);
    ui->stackedWidget->setCurrentWidget(main);
}


void MainWindow::on_chat_Button_clicked()
{
    chat* messeger = new chat(this);
    ui->stackedWidget->addWidget(messeger);
    ui->stackedWidget->setCurrentWidget(messeger);
}


void MainWindow::on_AlbomsButton_clicked()
{
    Albums* albums = new Albums(this);
    ui->stackedWidget->addWidget(albums);
    ui->stackedWidget->setCurrentWidget(albums);
}


void MainWindow::on_Friends_bar_clicked()
{
    Friends dialog;
    dialog.setModal(true);
    dialog.exec();
}


void MainWindow::on_input_friends_clicked()
{
    Friends_in dialog;
    dialog.setModal(true);
    dialog.exec();
}


void MainWindow::on_output_friends_clicked()
{
    Friends_out dialog;
    dialog.setModal(true);
    dialog.exec();
}


void MainWindow::on_VK_button_clicked()
{
    onVK* onvk = new onVK(this);
    ui->stackedWidget->addWidget(onvk);
    ui->stackedWidget->setCurrentWidget(onvk);
}


void MainWindow::on_YT_Button_clicked()
{
    onYouTube* onyt = new onYouTube(this);
    ui->stackedWidget->addWidget(onyt);
    ui->stackedWidget->setCurrentWidget(onyt);
}


void MainWindow::on_Config_button_clicked()
{
    Config* conf = new Config(this);
    ui->stackedWidget->addWidget(conf);
    ui->stackedWidget->setCurrentWidget(conf);
}


void MainWindow::on_button_login_clicked()
{
    Login dialog;
    dialog.setModal(true);
    dialog.exec();
}


void MainWindow::on_signUp_button_clicked()
{
    SignUp dialog;
    dialog.setModal(true);
    dialog.exec();
}

