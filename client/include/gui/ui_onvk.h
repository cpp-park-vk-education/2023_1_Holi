/********************************************************************************
** Form generated from reading UI file 'onvk.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONVK_H
#define UI_ONVK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_onVK
{
public:
    QListWidget *list_vk_auth;
    QPushButton *auth_VK;

    void setupUi(QWidget *onVK)
    {
        if (onVK->objectName().isEmpty())
            onVK->setObjectName(QString::fromUtf8("onVK"));
        onVK->resize(731, 491);
        list_vk_auth = new QListWidget(onVK);
        list_vk_auth->setObjectName(QString::fromUtf8("list_vk_auth"));
        list_vk_auth->setGeometry(QRect(245, 0, 421, 481));
        list_vk_auth->setStyleSheet(QString::fromUtf8("border: 1px solid #ffffff;\n"
"border-radius: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));"));
        auth_VK = new QPushButton(onVK);
        auth_VK->setObjectName(QString::fromUtf8("auth_VK"));
        auth_VK->setGeometry(QRect(30, 0, 142, 30));
        auth_VK->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Play"));
        font.setBold(true);
        auth_VK->setFont(font);
        auth_VK->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(onVK);

        QMetaObject::connectSlotsByName(onVK);
    } // setupUi

    void retranslateUi(QWidget *onVK)
    {
        onVK->setWindowTitle(QCoreApplication::translate("onVK", "Form", nullptr));
        auth_VK->setText(QCoreApplication::translate("onVK", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\222\320\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class onVK: public Ui_onVK {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONVK_H
