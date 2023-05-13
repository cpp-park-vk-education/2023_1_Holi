/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *signin_button;
    QLabel *password_label;
    QLineEdit *password_input;
    QLabel *login_label;
    QPushButton *login_button;
    QLabel *label;
    QPushButton *password_mask_button;
    QLabel *log_in_label_main;
    QFrame *line;
    QLineEdit *login_input;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(414, 736);
        Login->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(167, 62, 231, 255), stop:1 rgba(0, 235, 255, 255));\n"
""));
        signin_button = new QPushButton(Login);
        signin_button->setObjectName(QString::fromUtf8("signin_button"));
        signin_button->setGeometry(QRect(30, 603, 348, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Play"));
        font.setPointSize(14);
        signin_button->setFont(font);
        signin_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        password_label = new QLabel(Login);
        password_label->setObjectName(QString::fromUtf8("password_label"));
        password_label->setGeometry(QRect(30, 456, 61, 17));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Play"));
        font1.setPointSize(12);
        password_label->setFont(font1);
        password_label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(29, 35, 77);"));
        password_input = new QLineEdit(Login);
        password_input->setObjectName(QString::fromUtf8("password_input"));
        password_input->setGeometry(QRect(30, 476, 348, 33));
        password_input->setCursor(QCursor(Qt::ArrowCursor));
        password_input->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"border: 0.5px solid #000000;\n"
"border-radius: 10px;"));
        login_label = new QLabel(Login);
        login_label->setObjectName(QString::fromUtf8("login_label"));
        login_label->setGeometry(QRect(30, 390, 47, 17));
        login_label->setFont(font1);
        login_label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(29, 35, 77);"));
        login_button = new QPushButton(Login);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        login_button->setGeometry(QRect(30, 542, 348, 41));
        login_button->setFont(font);
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
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(67, 70, 276, 97));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Play"));
        font2.setPointSize(90);
        font2.setBold(true);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: rgb(72, 49, 157);\n"
"background-color: qlineargradient(0);"));
        password_mask_button = new QPushButton(Login);
        password_mask_button->setObjectName(QString::fromUtf8("password_mask_button"));
        password_mask_button->setGeometry(QRect(343, 481, 24, 24));
        password_mask_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border-bottom: 1px solid rgb(72, 49, 157);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../vks/static/svg/password_mask_icon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        password_mask_button->setIcon(icon);
        password_mask_button->setIconSize(QSize(24, 24));
        password_mask_button->setCheckable(true);
        log_in_label_main = new QLabel(Login);
        log_in_label_main->setObjectName(QString::fromUtf8("log_in_label_main"));
        log_in_label_main->setGeometry(QRect(29, 338, 80, 32));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Play"));
        font3.setPointSize(21);
        log_in_label_main->setFont(font3);
        log_in_label_main->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(0);\n"
"color: rgb(29, 35, 77);"));
        line = new QFrame(Login);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(30, 308, 348, 3));
        line->setStyleSheet(QString::fromUtf8("border: 0.7px solid #E8E7FF;\n"
"background-color: rgb(232, 231, 255);\n"
"color: #E8E7FF;\n"
""));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        login_input = new QLineEdit(Login);
        login_input->setObjectName(QString::fromUtf8("login_input"));
        login_input->setGeometry(QRect(30, 410, 348, 33));
        login_input->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"border: 0.5px solid #000000;\n"
"border-radius: 10px;"));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        signin_button->setText(QCoreApplication::translate("Login", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\260\320\272\320\272\320\260\321\203\320\275\321\202", nullptr));
        password_label->setText(QCoreApplication::translate("Login", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        login_label->setText(QCoreApplication::translate("Login", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        login_button->setText(QCoreApplication::translate("Login", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        label->setText(QCoreApplication::translate("Login", "HOLI", nullptr));
        password_mask_button->setText(QString());
        log_in_label_main->setText(QCoreApplication::translate("Login", "\320\222\320\276\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
