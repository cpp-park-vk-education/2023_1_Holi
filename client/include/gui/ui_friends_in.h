/********************************************************************************
** Form generated from reading UI file 'friends_in.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDS_IN_H
#define UI_FRIENDS_IN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Friends_in
{
public:
    QListWidget *listWidget;
    QPushButton *accept;
    QPushButton *cancel;

    void setupUi(QDialog *Friends_in)
    {
        if (Friends_in->objectName().isEmpty())
            Friends_in->setObjectName(QString::fromUtf8("Friends_in"));
        Friends_in->resize(400, 655);
        Friends_in->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(167, 62, 231, 255), stop:1 rgba(0, 235, 255, 255));\n"
""));
        listWidget = new QListWidget(Friends_in);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 30, 361, 491));
        listWidget->setStyleSheet(QString::fromUtf8("border: 1px solid #ffffff;\n"
"border-radius: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));"));
        accept = new QPushButton(Friends_in);
        accept->setObjectName(QString::fromUtf8("accept"));
        accept->setGeometry(QRect(20, 540, 121, 30));
        accept->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Play"));
        font.setBold(true);
        accept->setFont(font);
        accept->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        cancel = new QPushButton(Friends_in);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(150, 540, 121, 30));
        cancel->setMinimumSize(QSize(0, 30));
        cancel->setFont(font);
        cancel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(Friends_in);

        QMetaObject::connectSlotsByName(Friends_in);
    } // setupUi

    void retranslateUi(QDialog *Friends_in)
    {
        Friends_in->setWindowTitle(QCoreApplication::translate("Friends_in", "Dialog", nullptr));
        accept->setText(QCoreApplication::translate("Friends_in", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", nullptr));
        cancel->setText(QCoreApplication::translate("Friends_in", "\320\236\321\202\320\272\320\273\320\276\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Friends_in: public Ui_Friends_in {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDS_IN_H
