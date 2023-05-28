/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QStackedWidget *stackedWidget;
    QWidget *mainpage;
    QComboBox *YouTube_main_type_request;
    QComboBox *VK_main_playists;
    QPushButton *VK_getAllAlboms;
    QComboBox *VK_main_type_request;
    QPushButton *YouTube_getAllAlboms;
    QComboBox *YouTube_main_playists;
    QListWidget *VK_main_list_item;
    QListWidget *YouTube_main_list_item;
    QWidget *login;
    QLineEdit *password_input_2;
    QLabel *password_label_2;
    QLabel *log_in_label_main;
    QLabel *label_2;
    QLabel *login_label;
    QPushButton *signin_button_2;
    QLineEdit *login_input;
    QPushButton *login_button;
    QFrame *line_3;
    QWidget *settings;
    QLabel *Label_Video_3;
    QListWidget *listWidget_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_3;
    QPushButton *vk_auth_config;
    QPushButton *delete_config;
    QLabel *Label_Video_2;
    QPushButton *save_config;
    QPushButton *youtube_auth_config;
    QWidget *albums;
    QGroupBox *groupBox;
    QLabel *Label_Video;
    QLabel *Service;
    QTextBrowser *textBrowser;
    QLabel *IMG;
    QTreeWidget *treeWidget;
    QWidget *signup;
    QLineEdit *password_input;
    QLineEdit *signin_input;
    QFrame *line_2;
    QPushButton *password_mask;
    QLabel *label_create;
    QLabel *password_label;
    QLabel *signin_label;
    QLabel *signin_label_2;
    QPushButton *signin_button;
    QLineEdit *signin_input_2;
    QWidget *verticalWidget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *main_button;
    QPushButton *AlbomsButton;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QPushButton *VK_button;
    QPushButton *YT_Button;
    QPushButton *Config_button;
    QSpacerItem *verticalSpacer_3;
    QPushButton *button_login;
    QPushButton *signUp_button;
    QPushButton *logout;
    QLabel *label;
    QPushButton *password_mask_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(952, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(167, 62, 231, 255), stop:1 rgba(0, 235, 255, 255));\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(180, -20, 20, 601));
        line->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:1 rgba(0, 0, 0, 0));"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setEnabled(true);
        stackedWidget->setGeometry(QRect(190, 20, 731, 491));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:1 rgba(0, 0, 0, 0));"));
        mainpage = new QWidget();
        mainpage->setObjectName(QString::fromUtf8("mainpage"));
        YouTube_main_type_request = new QComboBox(mainpage);
        YouTube_main_type_request->addItem(QString());
        YouTube_main_type_request->addItem(QString());
        YouTube_main_type_request->setObjectName(QString::fromUtf8("YouTube_main_type_request"));
        YouTube_main_type_request->setGeometry(QRect(470, 10, 81, 22));
        YouTube_main_type_request->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 193, 241);"));
        VK_main_playists = new QComboBox(mainpage);
        VK_main_playists->setObjectName(QString::fromUtf8("VK_main_playists"));
        VK_main_playists->setGeometry(QRect(220, 10, 111, 22));
        VK_main_playists->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 193, 241);"));
        VK_getAllAlboms = new QPushButton(mainpage);
        VK_getAllAlboms->setObjectName(QString::fromUtf8("VK_getAllAlboms"));
        VK_getAllAlboms->setGeometry(QRect(50, 10, 71, 25));
        VK_getAllAlboms->setContextMenuPolicy(Qt::NoContextMenu);
        VK_getAllAlboms->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(72, 49, 157);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}\n"
""));
        VK_main_type_request = new QComboBox(mainpage);
        VK_main_type_request->addItem(QString());
        VK_main_type_request->addItem(QString());
        VK_main_type_request->setObjectName(QString::fromUtf8("VK_main_type_request"));
        VK_main_type_request->setGeometry(QRect(130, 10, 81, 22));
        VK_main_type_request->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 193, 241);"));
        YouTube_getAllAlboms = new QPushButton(mainpage);
        YouTube_getAllAlboms->setObjectName(QString::fromUtf8("YouTube_getAllAlboms"));
        YouTube_getAllAlboms->setGeometry(QRect(380, 10, 81, 25));
        YouTube_getAllAlboms->setContextMenuPolicy(Qt::NoContextMenu);
        YouTube_getAllAlboms->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(72, 49, 157);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}\n"
""));
        YouTube_main_playists = new QComboBox(mainpage);
        YouTube_main_playists->setObjectName(QString::fromUtf8("YouTube_main_playists"));
        YouTube_main_playists->setGeometry(QRect(560, 10, 101, 22));
        YouTube_main_playists->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 193, 241);"));
        YouTube_main_playists->setEditable(false);
        VK_main_list_item = new QListWidget(mainpage);
        VK_main_list_item->setObjectName(QString::fromUtf8("VK_main_list_item"));
        VK_main_list_item->setGeometry(QRect(50, 40, 281, 411));
        VK_main_list_item->setStyleSheet(QString::fromUtf8("border: 1px solid #ffffff;\n"
"border-radius: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));"));
        YouTube_main_list_item = new QListWidget(mainpage);
        YouTube_main_list_item->setObjectName(QString::fromUtf8("YouTube_main_list_item"));
        YouTube_main_list_item->setGeometry(QRect(380, 40, 281, 411));
        YouTube_main_list_item->setStyleSheet(QString::fromUtf8("border: 1px solid #ffffff;\n"
"border-radius: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));"));
        stackedWidget->addWidget(mainpage);
        login = new QWidget();
        login->setObjectName(QString::fromUtf8("login"));
        password_input_2 = new QLineEdit(login);
        password_input_2->setObjectName(QString::fromUtf8("password_input_2"));
        password_input_2->setGeometry(QRect(190, 293, 348, 33));
        password_input_2->setCursor(QCursor(Qt::ArrowCursor));
        password_input_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"border: 0.5px solid #000000;\n"
"border-radius: 10px;"));
        password_input_2->setEchoMode(QLineEdit::Password);
        password_label_2 = new QLabel(login);
        password_label_2->setObjectName(QString::fromUtf8("password_label_2"));
        password_label_2->setGeometry(QRect(190, 273, 61, 17));
        QFont font;
        font.setFamily(QString::fromUtf8("Play"));
        font.setPointSize(12);
        password_label_2->setFont(font);
        password_label_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(29, 35, 77);"));
        log_in_label_main = new QLabel(login);
        log_in_label_main->setObjectName(QString::fromUtf8("log_in_label_main"));
        log_in_label_main->setGeometry(QRect(189, 155, 91, 32));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Play"));
        font1.setPointSize(21);
        log_in_label_main->setFont(font1);
        log_in_label_main->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(0);\n"
"color: rgb(29, 35, 77);"));
        label_2 = new QLabel(login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 20, 341, 97));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Play"));
        font2.setPointSize(90);
        font2.setBold(true);

        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(72, 49, 157);\n"
"background-color: qlineargradient(0);"));
        login_label = new QLabel(login);
        login_label->setObjectName(QString::fromUtf8("login_label"));
        login_label->setGeometry(QRect(190, 207, 61, 17));
        login_label->setFont(font);
        login_label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(29, 35, 77);"));
        signin_button_2 = new QPushButton(login);
        signin_button_2->setObjectName(QString::fromUtf8("signin_button_2"));
        signin_button_2->setGeometry(QRect(190, 420, 348, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Play"));
        font3.setPointSize(14);
        signin_button_2->setFont(font3);
        signin_button_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"border: 1px solid #454B79;\n"
"border-radius: 20px;\n"
"color: rgb(29, 35, 77);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 20px;\n"
"	border-color: rgba(102, 64, 191, 169);\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}"));
        login_input = new QLineEdit(login);
        login_input->setObjectName(QString::fromUtf8("login_input"));
        login_input->setGeometry(QRect(190, 227, 348, 33));
        login_input->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"border: 0.5px solid #000000;\n"
"border-radius: 10px;"));
        login_button = new QPushButton(login);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        login_button->setGeometry(QRect(190, 359, 348, 41));
        login_button->setFont(font3);
        login_button->setCursor(QCursor(Qt::ArrowCursor));
        login_button->setTabletTracking(false);
        login_button->setFocusPolicy(Qt::StrongFocus);
        login_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(72, 49, 157);\n"
"	border-radius: 20px;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 20px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}\n"
"\n"
""));
        line_3 = new QFrame(login);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(190, 130, 348, 3));
        line_3->setStyleSheet(QString::fromUtf8("border: 0.7px solid #E8E7FF;\n"
"background-color: rgb(232, 231, 255);\n"
"color: #E8E7FF;\n"
""));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        stackedWidget->addWidget(login);
        settings = new QWidget();
        settings->setObjectName(QString::fromUtf8("settings"));
        Label_Video_3 = new QLabel(settings);
        Label_Video_3->setObjectName(QString::fromUtf8("Label_Video_3"));
        Label_Video_3->setGeometry(QRect(180, 190, 181, 31));
        Label_Video_3->setStyleSheet(QString::fromUtf8("	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));\n"
"border: 0.5px solid #ffffff;\n"
"border-radius: 10px;"));
        listWidget_3 = new QListWidget(settings);
        new QListWidgetItem(listWidget_3);
        new QListWidgetItem(listWidget_3);
        new QListWidgetItem(listWidget_3);
        new QListWidgetItem(listWidget_3);
        new QListWidgetItem(listWidget_3);
        listWidget_3->setObjectName(QString::fromUtf8("listWidget_3"));
        listWidget_3->setGeometry(QRect(390, 30, 311, 441));
        listWidget_3->setStyleSheet(QString::fromUtf8("	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));\n"
"border: 0.5px solid #ffffff;\n"
"border-radius: 10px;"));
        lineEdit_4 = new QLineEdit(settings);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(30, 70, 331, 31));
        lineEdit_4->setStyleSheet(QString::fromUtf8("	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));\n"
"border: 0.5px solid #ffffff;\n"
"border-radius: 10px;"));
        lineEdit_5 = new QLineEdit(settings);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(30, 110, 331, 31));
        lineEdit_5->setStyleSheet(QString::fromUtf8("	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));\n"
"border: 0.5px solid #ffffff;\n"
"border-radius: 10px;"));
        lineEdit_3 = new QLineEdit(settings);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(30, 30, 331, 31));
        lineEdit_3->setStyleSheet(QString::fromUtf8("	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));\n"
"border: 0.5px solid #ffffff;\n"
"border-radius: 10px;"));
        vk_auth_config = new QPushButton(settings);
        vk_auth_config->setObjectName(QString::fromUtf8("vk_auth_config"));
        vk_auth_config->setGeometry(QRect(30, 150, 121, 30));
        vk_auth_config->setMinimumSize(QSize(0, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Play"));
        font4.setBold(true);

        vk_auth_config->setFont(font4);
        vk_auth_config->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(72, 49, 157);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}\n"
""));
        delete_config = new QPushButton(settings);
        delete_config->setObjectName(QString::fromUtf8("delete_config"));
        delete_config->setGeometry(QRect(180, 440, 181, 30));
        delete_config->setMinimumSize(QSize(0, 30));
        delete_config->setFont(font4);
        delete_config->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(72, 49, 157);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}\n"
""));
        Label_Video_2 = new QLabel(settings);
        Label_Video_2->setObjectName(QString::fromUtf8("Label_Video_2"));
        Label_Video_2->setGeometry(QRect(180, 150, 181, 31));
        Label_Video_2->setStyleSheet(QString::fromUtf8("	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));\n"
"border: 0.5px solid #ffffff;\n"
"border-radius: 10px;"));
        save_config = new QPushButton(settings);
        save_config->setObjectName(QString::fromUtf8("save_config"));
        save_config->setGeometry(QRect(30, 440, 121, 30));
        save_config->setMinimumSize(QSize(0, 30));
        save_config->setFont(font4);
        save_config->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(72, 49, 157);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}\n"
""));
        youtube_auth_config = new QPushButton(settings);
        youtube_auth_config->setObjectName(QString::fromUtf8("youtube_auth_config"));
        youtube_auth_config->setGeometry(QRect(30, 190, 121, 30));
        youtube_auth_config->setMinimumSize(QSize(0, 30));
        youtube_auth_config->setFont(font4);
        youtube_auth_config->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(72, 49, 157);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}\n"
""));
        stackedWidget->addWidget(settings);
        albums = new QWidget();
        albums->setObjectName(QString::fromUtf8("albums"));
        groupBox = new QGroupBox(albums);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(390, 10, 281, 471));
        groupBox->setStyleSheet(QString::fromUtf8("border: 1px solid #ffffff;\n"
"border-radius: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));"));
        Label_Video = new QLabel(groupBox);
        Label_Video->setObjectName(QString::fromUtf8("Label_Video"));
        Label_Video->setGeometry(QRect(10, 20, 181, 31));
        Service = new QLabel(groupBox);
        Service->setObjectName(QString::fromUtf8("Service"));
        Service->setGeometry(QRect(10, 60, 181, 16));
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 250, 211, 191));
        IMG = new QLabel(groupBox);
        IMG->setObjectName(QString::fromUtf8("IMG"));
        IMG->setGeometry(QRect(30, 100, 211, 141));
        treeWidget = new QTreeWidget(albums);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(40, 10, 271, 471));
        treeWidget->setStyleSheet(QString::fromUtf8("border: 1px solid #ffffff;\n"
"border-radius: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));"));
        stackedWidget->addWidget(albums);
        signup = new QWidget();
        signup->setObjectName(QString::fromUtf8("signup"));
        password_input = new QLineEdit(signup);
        password_input->setObjectName(QString::fromUtf8("password_input"));
        password_input->setGeometry(QRect(180, 256, 348, 33));
        password_input->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"border: 0.5px solid #000000;\n"
"border-radius: 10px;"));
        password_input->setEchoMode(QLineEdit::Password);
        signin_input = new QLineEdit(signup);
        signin_input->setObjectName(QString::fromUtf8("signin_input"));
        signin_input->setGeometry(QRect(180, 127, 348, 33));
        signin_input->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"border: 0.5px solid #000000;\n"
"border-radius: 10px;"));
        line_2 = new QFrame(signup);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(180, 89, 348, 1));
        line_2->setStyleSheet(QString::fromUtf8("border: 0.2px solid #E8E7FF;\n"
"background-color: rgb(232, 231, 255);\n"
"color: #E8E7FF;\n"
""));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        password_mask = new QPushButton(signup);
        password_mask->setObjectName(QString::fromUtf8("password_mask"));
        password_mask->setGeometry(QRect(497, 261, 24, 24));
        password_mask->setCursor(QCursor(Qt::ArrowCursor));
        password_mask->setMouseTracking(true);
        password_mask->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border-bottom: 1px solid rgb(72, 49, 157);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../vks/static/svg/password_mask_icon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        password_mask->setIcon(icon);
        password_mask->setIconSize(QSize(24, 24));
        password_mask->setCheckable(true);
        label_create = new QLabel(signup);
        label_create->setObjectName(QString::fromUtf8("label_create"));
        label_create->setGeometry(QRect(180, 25, 354, 51));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Play"));
        font5.setPointSize(28);
        label_create->setFont(font5);
        label_create->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"\n"
"color: rgb(29, 35, 77);"));
        password_label = new QLabel(signup);
        password_label->setObjectName(QString::fromUtf8("password_label"));
        password_label->setGeometry(QRect(180, 236, 61, 17));
        password_label->setFont(font);
        password_label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(29, 35, 77);"));
        signin_label = new QLabel(signup);
        signin_label->setObjectName(QString::fromUtf8("signin_label"));
        signin_label->setGeometry(QRect(180, 107, 141, 17));
        signin_label->setFont(font);
        signin_label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(29, 35, 77);"));
        signin_label_2 = new QLabel(signup);
        signin_label_2->setObjectName(QString::fromUtf8("signin_label_2"));
        signin_label_2->setGeometry(QRect(180, 169, 47, 17));
        signin_label_2->setFont(font);
        signin_label_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(29, 35, 77);"));
        signin_button = new QPushButton(signup);
        signin_button->setObjectName(QString::fromUtf8("signin_button"));
        signin_button->setGeometry(QRect(180, 360, 348, 41));
        signin_button->setFont(font3);
        signin_button->setCursor(QCursor(Qt::ArrowCursor));
        signin_button->setTabletTracking(false);
        signin_button->setFocusPolicy(Qt::StrongFocus);
        signin_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(72, 49, 157);\n"
"	border-radius: 20px;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 20px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}\n"
"\n"
""));
        signin_input_2 = new QLineEdit(signup);
        signin_input_2->setObjectName(QString::fromUtf8("signin_input_2"));
        signin_input_2->setGeometry(QRect(180, 190, 348, 33));
        signin_input_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"border: 0.5px solid #000000;\n"
"border-radius: 10px;"));
        stackedWidget->addWidget(signup);
        verticalWidget_2 = new QWidget(centralwidget);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        verticalWidget_2->setGeometry(QRect(10, 80, 160, 451));
        verticalWidget_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:1 rgba(0, 0, 0, 0));"));
        verticalLayout_3 = new QVBoxLayout(verticalWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        main_button = new QPushButton(verticalWidget_2);
        main_button->setObjectName(QString::fromUtf8("main_button"));
        main_button->setMinimumSize(QSize(62, 19));
        main_button->setFont(font);
        main_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}\n"
""));

        verticalLayout_3->addWidget(main_button, 0, Qt::AlignLeft);

        AlbomsButton = new QPushButton(verticalWidget_2);
        AlbomsButton->setObjectName(QString::fromUtf8("AlbomsButton"));
        AlbomsButton->setFont(font);
        AlbomsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}\n"
""));

        verticalLayout_3->addWidget(AlbomsButton, 0, Qt::AlignLeft);

        verticalSpacer = new QSpacerItem(155, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        label_3 = new QLabel(verticalWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Play"));
        font6.setPointSize(12);
        font6.setBold(true);

        label_3->setFont(font6);
        label_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(232, 231, 255);\n"
""));

        verticalLayout_3->addWidget(label_3);

        VK_button = new QPushButton(verticalWidget_2);
        VK_button->setObjectName(QString::fromUtf8("VK_button"));
        VK_button->setFont(font);
        VK_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}\n"
""));

        verticalLayout_3->addWidget(VK_button, 0, Qt::AlignLeft);

        YT_Button = new QPushButton(verticalWidget_2);
        YT_Button->setObjectName(QString::fromUtf8("YT_Button"));
        YT_Button->setFont(font);
        YT_Button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}\n"
""));

        verticalLayout_3->addWidget(YT_Button, 0, Qt::AlignLeft);

        Config_button = new QPushButton(verticalWidget_2);
        Config_button->setObjectName(QString::fromUtf8("Config_button"));
        Config_button->setFont(font);
        Config_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}\n"
""));

        verticalLayout_3->addWidget(Config_button, 0, Qt::AlignLeft);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        button_login = new QPushButton(verticalWidget_2);
        button_login->setObjectName(QString::fromUtf8("button_login"));
        button_login->setMinimumSize(QSize(0, 30));
        button_login->setFont(font4);
        button_login->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(72, 49, 157);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}\n"
""));

        verticalLayout_3->addWidget(button_login);

        signUp_button = new QPushButton(verticalWidget_2);
        signUp_button->setObjectName(QString::fromUtf8("signUp_button"));
        signUp_button->setMinimumSize(QSize(0, 30));
        signUp_button->setFont(font4);
        signUp_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(72, 49, 157);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}\n"
"\n"
""));

        verticalLayout_3->addWidget(signUp_button);

        logout = new QPushButton(verticalWidget_2);
        logout->setObjectName(QString::fromUtf8("logout"));
        logout->setEnabled(true);
        logout->setMinimumSize(QSize(0, 30));
        logout->setFont(font4);
        logout->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(72, 49, 157);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(102, 64, 191, 169);\n"
"	border-radius: 5px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"}\n"
""));

        verticalLayout_3->addWidget(logout);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 161, 91));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Play"));
        font7.setPointSize(44);
        font7.setBold(true);

        label->setFont(font7);
        label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(232, 231, 255);\n"
""));
        password_mask_button = new QPushButton(centralwidget);
        password_mask_button->setObjectName(QString::fromUtf8("password_mask_button"));
        password_mask_button->setGeometry(QRect(696, 331, 24, 24));
        password_mask_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border-bottom: 1px solid rgb(72, 49, 157);\n"
"}"));
        password_mask_button->setIcon(icon);
        password_mask_button->setIconSize(QSize(24, 24));
        password_mask_button->setCheckable(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 952, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        YouTube_main_type_request->setItemText(0, QCoreApplication::translate("MainWindow", "\320\220\320\273\321\214\320\261\320\276\320\274\321\213", nullptr));
        YouTube_main_type_request->setItemText(1, QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\265\320\276", nullptr));

        VK_getAllAlboms->setText(QCoreApplication::translate("MainWindow", "\320\222\320\232", nullptr));
        VK_main_type_request->setItemText(0, QCoreApplication::translate("MainWindow", "\320\220\320\273\321\214\320\261\320\276\320\274\321\213", nullptr));
        VK_main_type_request->setItemText(1, QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\265\320\276", nullptr));

        YouTube_getAllAlboms->setText(QCoreApplication::translate("MainWindow", "YouTube", nullptr));
        password_label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        log_in_label_main->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "HOLI", nullptr));
        login_label->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        signin_button_2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\260\320\272\320\272\320\260\321\203\320\275\321\202", nullptr));
        login_button->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        Label_Video_3->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201/\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));

        const bool __sortingEnabled = listWidget_3->isSortingEnabled();
        listWidget_3->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_3->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\277\321\200\320\276\321\204\320\270\320\273\320\265", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_3->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217: \320\235\320\260\321\202\320\260\321\210\320\260", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_3->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\273\320\270\321\207\320\265\321\201\320\272\320\262\320\276 \320\264\321\200\321\203\320\267\320\265\320\271: 50", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_3->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\320\273\320\265\320\271\320\273\320\270\321\201\321\202\320\276\320\262: 20", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_3->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270: 2001", nullptr));
        listWidget_3->setSortingEnabled(__sortingEnabled);

        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        vk_auth_config->setText(QCoreApplication::translate("MainWindow", "VK", nullptr));
        delete_config->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        Label_Video_2->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201/\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        save_config->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        youtube_auth_config->setText(QCoreApplication::translate("MainWindow", "YouTube", nullptr));
        groupBox->setTitle(QString());
        Label_Video->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        Service->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\321\200\320\262\320\270\321\201", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:9pt;\">\320\255\321\202\320\276 \320\261\321\203\320\264\320\265\321\202 \320\276\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\262\320\270\320\264\320\276\321\201\320\270\320\272\320\260</span></p></body></html>", nullptr));
        IMG->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "\320\234\320\276\320\270 \320\262\320\270\320\264\320\265\320\276", nullptr));

        const bool __sortingEnabled1 = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\276\321\201\320\270\320\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\276\321\201\320\270\320\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\276\321\201\320\270\320\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("MainWindow", "\320\237\320\273\320\265\320\271\320\273\320\270\321\201\321\202", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem4->child(0);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\276\321\201\320\270\320\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem4->child(1);
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\276\321\201\320\270\320\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem4->child(2);
        ___qtreewidgetitem7->setText(0, QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\276\321\201\320\270\320\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem4->child(3);
        ___qtreewidgetitem8->setText(0, QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\276\321\201\320\270\320\272", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled1);

        password_mask->setText(QString());
        label_create->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\260\320\272\320\272\320\260\321\203\320\275\321\202", nullptr));
        password_label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        signin_label->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        signin_label_2->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        signin_button->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        main_button->setText(QCoreApplication::translate("MainWindow", "\320\223\320\273\320\260\320\262\320\275\320\260\321\217", nullptr));
        AlbomsButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\270 \320\260\320\273\321\214\320\261\320\276\320\274\321\213", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\321\200\320\262\320\270\321\201\321\213", nullptr));
        VK_button->setText(QCoreApplication::translate("MainWindow", "VK", nullptr));
        YT_Button->setText(QCoreApplication::translate("MainWindow", "YouTube", nullptr));
        Config_button->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        button_login->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        signUp_button->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        logout->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "HOLI", nullptr));
        password_mask_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
