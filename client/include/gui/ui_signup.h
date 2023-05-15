/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QPushButton *signin_button;
    QFrame *line_2;
    QLabel *signin_label;
    QLabel *LOGO;
    QPushButton *back;
    QPushButton *password_mask;
    QLineEdit *signin_input_2;
    QLabel *signin_label_2;
    QLineEdit *password_input;
    QLabel *label_create;
    QLabel *password_label;
    QLineEdit *signin_input;

    void setupUi(QDialog *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName(QString::fromUtf8("SignUp"));
        SignUp->resize(414, 736);
        SignUp->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(167, 62, 231, 255), stop:1 rgba(0, 235, 255, 255));\n"
""));
        signin_button = new QPushButton(SignUp);
        signin_button->setObjectName(QString::fromUtf8("signin_button"));
        signin_button->setGeometry(QRect(30, 407, 348, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Play"));
        font.setPointSize(14);
        signin_button->setFont(font);
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
        line_2 = new QFrame(SignUp);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(30, 172, 348, 1));
        line_2->setStyleSheet(QString::fromUtf8("border: 0.2px solid #E8E7FF;\n"
"background-color: rgb(232, 231, 255);\n"
"color: #E8E7FF;\n"
""));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        signin_label = new QLabel(SignUp);
        signin_label->setObjectName(QString::fromUtf8("signin_label"));
        signin_label->setGeometry(QRect(30, 190, 141, 17));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Play"));
        font1.setPointSize(12);
        signin_label->setFont(font1);
        signin_label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(29, 35, 77);"));
        LOGO = new QLabel(SignUp);
        LOGO->setObjectName(QString::fromUtf8("LOGO"));
        LOGO->setGeometry(QRect(67, 502, 276, 97));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Play"));
        font2.setPointSize(90);
        font2.setBold(true);
        LOGO->setFont(font2);
        LOGO->setStyleSheet(QString::fromUtf8("color: rgb(72, 49, 157);\n"
"background-color: qlineargradient(0);"));
        back = new QPushButton(SignUp);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(30, 87, 16, 16));
        back->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"border: none;\n"
"}\n"
"QPushButton:hover{\n"
"	border-bottom: 1px solid rgb(72, 49, 157);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../vks/static/svg/arrow.svg"), QSize(), QIcon::Normal, QIcon::Off);
        back->setIcon(icon);
        password_mask = new QPushButton(SignUp);
        password_mask->setObjectName(QString::fromUtf8("password_mask"));
        password_mask->setGeometry(QRect(347, 344, 24, 24));
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../vks/static/svg/password_mask_icon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        password_mask->setIcon(icon1);
        password_mask->setIconSize(QSize(24, 24));
        password_mask->setCheckable(true);
        signin_input_2 = new QLineEdit(SignUp);
        signin_input_2->setObjectName(QString::fromUtf8("signin_input_2"));
        signin_input_2->setGeometry(QRect(30, 273, 348, 33));
        signin_input_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"border: 0.5px solid #000000;\n"
"border-radius: 10px;"));
        signin_label_2 = new QLabel(SignUp);
        signin_label_2->setObjectName(QString::fromUtf8("signin_label_2"));
        signin_label_2->setGeometry(QRect(30, 252, 47, 17));
        signin_label_2->setFont(font1);
        signin_label_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(29, 35, 77);"));
        password_input = new QLineEdit(SignUp);
        password_input->setObjectName(QString::fromUtf8("password_input"));
        password_input->setGeometry(QRect(30, 339, 348, 33));
        password_input->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"border: 0.5px solid #000000;\n"
"border-radius: 10px;"));
        password_input->setEchoMode(QLineEdit::Password);
        label_create = new QLabel(SignUp);
        label_create->setObjectName(QString::fromUtf8("label_create"));
        label_create->setGeometry(QRect(30, 108, 354, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Play"));
        font3.setPointSize(28);
        label_create->setFont(font3);
        label_create->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"\n"
"color: rgb(29, 35, 77);"));
        password_label = new QLabel(SignUp);
        password_label->setObjectName(QString::fromUtf8("password_label"));
        password_label->setGeometry(QRect(30, 319, 61, 17));
        password_label->setFont(font1);
        password_label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(29, 35, 77);"));
        signin_input = new QLineEdit(SignUp);
        signin_input->setObjectName(QString::fromUtf8("signin_input"));
        signin_input->setGeometry(QRect(30, 210, 348, 33));
        signin_input->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"border: 0.5px solid #000000;\n"
"border-radius: 10px;"));

        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QDialog *SignUp)
    {
        SignUp->setWindowTitle(QCoreApplication::translate("SignUp", "Dialog", nullptr));
        signin_button->setText(QCoreApplication::translate("SignUp", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        signin_label->setText(QCoreApplication::translate("SignUp", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        LOGO->setText(QCoreApplication::translate("SignUp", "HOLI", nullptr));
        back->setText(QString());
        password_mask->setText(QString());
        signin_label_2->setText(QCoreApplication::translate("SignUp", "Email", nullptr));
        label_create->setText(QCoreApplication::translate("SignUp", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\260\320\272\320\272\320\260\321\203\320\275\321\202", nullptr));
        password_label->setText(QCoreApplication::translate("SignUp", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
