/********************************************************************************
** Form generated from reading UI file 'onyoutube.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONYOUTUBE_H
#define UI_ONYOUTUBE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_onYouTube
{
public:
    QPushButton *auth_YouTube;
    QListWidget *list_youtube_auth;

    void setupUi(QWidget *onYouTube)
    {
        if (onYouTube->objectName().isEmpty())
            onYouTube->setObjectName(QString::fromUtf8("onYouTube"));
        onYouTube->resize(731, 491);
        auth_YouTube = new QPushButton(onYouTube);
        auth_YouTube->setObjectName(QString::fromUtf8("auth_YouTube"));
        auth_YouTube->setGeometry(QRect(25, 0, 142, 30));
        auth_YouTube->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Play"));
        font.setBold(true);
        auth_YouTube->setFont(font);
        auth_YouTube->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        list_youtube_auth = new QListWidget(onYouTube);
        list_youtube_auth->setObjectName(QString::fromUtf8("list_youtube_auth"));
        list_youtube_auth->setGeometry(QRect(240, 0, 421, 481));
        list_youtube_auth->setStyleSheet(QString::fromUtf8("border: 1px solid #ffffff;\n"
"border-radius: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));"));

        retranslateUi(onYouTube);

        QMetaObject::connectSlotsByName(onYouTube);
    } // setupUi

    void retranslateUi(QWidget *onYouTube)
    {
        onYouTube->setWindowTitle(QCoreApplication::translate("onYouTube", "Form", nullptr));
        auth_YouTube->setText(QCoreApplication::translate("onYouTube", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214 YouTube", nullptr));
    } // retranslateUi

};

namespace Ui {
    class onYouTube: public Ui_onYouTube {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONYOUTUBE_H
