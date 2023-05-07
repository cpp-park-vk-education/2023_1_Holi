/********************************************************************************
** Form generated from reading UI file 'friends_out.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDS_OUT_H
#define UI_FRIENDS_OUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Friends_out
{
public:
    QListWidget *listWidget;
    QPushButton *cancel_request;

    void setupUi(QDialog *Friends_out)
    {
        if (Friends_out->objectName().isEmpty())
            Friends_out->setObjectName(QString::fromUtf8("Friends_out"));
        Friends_out->resize(400, 590);
        Friends_out->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(167, 62, 231, 255), stop:1 rgba(0, 235, 255, 255));\n"
""));
        listWidget = new QListWidget(Friends_out);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 20, 361, 491));
        listWidget->setStyleSheet(QString::fromUtf8("border: 1px solid #ffffff;\n"
"border-radius: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));"));
        cancel_request = new QPushButton(Friends_out);
        cancel_request->setObjectName(QString::fromUtf8("cancel_request"));
        cancel_request->setGeometry(QRect(20, 530, 121, 30));
        cancel_request->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Play"));
        font.setBold(true);
        cancel_request->setFont(font);
        cancel_request->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(Friends_out);

        QMetaObject::connectSlotsByName(Friends_out);
    } // setupUi

    void retranslateUi(QDialog *Friends_out)
    {
        Friends_out->setWindowTitle(QCoreApplication::translate("Friends_out", "Dialog", nullptr));
        cancel_request->setText(QCoreApplication::translate("Friends_out", "\320\236\321\202\320\276\320\267\320\262\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Friends_out: public Ui_Friends_out {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDS_OUT_H
