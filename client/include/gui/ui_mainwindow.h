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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
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
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QPushButton *VK_button;
    QPushButton *YT_Button;
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
        MainWindow->setMinimumSize(QSize(952, 600));
        MainWindow->setMaximumSize(QSize(952, 600));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(167, 62, 231, 255), stop:1 rgba(0, 235, 255, 255));\n"
"\n"
"QStatusBar {\n"
" 	\321\201olor: white;\n"
"}"));
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
        stackedWidget->setGeometry(QRect(190, 20, 751, 531));
        stackedWidget->setMinimumSize(QSize(751, 531));
        stackedWidget->setMaximumSize(QSize(751, 531));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:1 rgba(0, 0, 0, 0));"));
        mainpage = new QWidget();
        mainpage->setObjectName(QString::fromUtf8("mainpage"));
        YouTube_main_type_request = new QComboBox(mainpage);
        YouTube_main_type_request->addItem(QString());
        YouTube_main_type_request->addItem(QString());
        YouTube_main_type_request->setObjectName(QString::fromUtf8("YouTube_main_type_request"));
        YouTube_main_type_request->setGeometry(QRect(480, 10, 121, 22));
        YouTube_main_type_request->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 193, 241);"));
        VK_main_playists = new QComboBox(mainpage);
        VK_main_playists->setObjectName(QString::fromUtf8("VK_main_playists"));
        VK_main_playists->setGeometry(QRect(250, 10, 121, 22));
        VK_main_playists->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 193, 241);"));
        VK_getAllAlboms = new QPushButton(mainpage);
        VK_getAllAlboms->setObjectName(QString::fromUtf8("VK_getAllAlboms"));
        VK_getAllAlboms->setGeometry(QRect(30, 10, 81, 25));
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
        VK_main_type_request->setGeometry(QRect(120, 10, 121, 22));
        VK_main_type_request->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 193, 241);"));
        YouTube_getAllAlboms = new QPushButton(mainpage);
        YouTube_getAllAlboms->setObjectName(QString::fromUtf8("YouTube_getAllAlboms"));
        YouTube_getAllAlboms->setGeometry(QRect(390, 10, 81, 25));
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
        YouTube_main_playists->setGeometry(QRect(610, 10, 121, 22));
        YouTube_main_playists->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 193, 241);"));
        YouTube_main_playists->setEditable(false);
        VK_main_list_item = new QListWidget(mainpage);
        VK_main_list_item->setObjectName(QString::fromUtf8("VK_main_list_item"));
        VK_main_list_item->setGeometry(QRect(30, 40, 341, 481));
        VK_main_list_item->setStyleSheet(QString::fromUtf8("border: 1px solid #ffffff;\n"
"border-radius: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));\n"
"\n"
""));
        VK_main_list_item->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        VK_main_list_item->setResizeMode(QListView::Adjust);
        VK_main_list_item->setSpacing(7);
        VK_main_list_item->setGridSize(QSize(0, 25));
        VK_main_list_item->setWordWrap(false);
        YouTube_main_list_item = new QListWidget(mainpage);
        YouTube_main_list_item->setObjectName(QString::fromUtf8("YouTube_main_list_item"));
        YouTube_main_list_item->setGeometry(QRect(390, 40, 341, 481));
        YouTube_main_list_item->setStyleSheet(QString::fromUtf8("border: 1px solid #ffffff;\n"
"border-radius: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));"));
        YouTube_main_list_item->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        YouTube_main_list_item->setResizeMode(QListView::Adjust);
        YouTube_main_list_item->setSpacing(7);
        YouTube_main_list_item->setGridSize(QSize(0, 25));
        YouTube_main_list_item->setWordWrap(false);
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
        QFont font4;
        font4.setFamily(QString::fromUtf8("Play"));
        font4.setPointSize(28);
        label_create->setFont(font4);
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
        signin_label->setGeometry(QRect(180, 107, 161, 17));
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

        verticalSpacer = new QSpacerItem(130, 100, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        label_3 = new QLabel(verticalWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Play"));
        font5.setPointSize(12);
        font5.setBold(true);

        label_3->setFont(font5);
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

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        button_login = new QPushButton(verticalWidget_2);
        button_login->setObjectName(QString::fromUtf8("button_login"));
        button_login->setMinimumSize(QSize(0, 30));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Play"));
        font6.setBold(true);

        button_login->setFont(font6);
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
        signUp_button->setFont(font6);
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
        logout->setFont(font6);
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
        statusbar->setAutoFillBackground(false);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        YouTube_main_type_request->setCurrentIndex(0);


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
        password_mask->setText(QString());
        label_create->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\260\320\272\320\272\320\260\321\203\320\275\321\202", nullptr));
        password_label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        signin_label->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        signin_label_2->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        signin_button->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        main_button->setText(QCoreApplication::translate("MainWindow", "\320\223\320\273\320\260\320\262\320\275\320\260\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\321\200\320\262\320\270\321\201\321\213", nullptr));
        VK_button->setText(QCoreApplication::translate("MainWindow", "VK", nullptr));
        YT_Button->setText(QCoreApplication::translate("MainWindow", "YouTube", nullptr));
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
