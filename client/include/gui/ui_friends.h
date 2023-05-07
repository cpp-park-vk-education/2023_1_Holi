/********************************************************************************
** Form generated from reading UI file 'friends.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDS_H
#define UI_FRIENDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_Friends
{
public:
    QListWidget *listWidget;

    void setupUi(QDialog *Friends)
    {
        if (Friends->objectName().isEmpty())
            Friends->setObjectName(QString::fromUtf8("Friends"));
        Friends->resize(400, 653);
        Friends->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(167, 62, 231, 255), stop:1 rgba(0, 235, 255, 255));\n"
""));
        listWidget = new QListWidget(Friends);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 30, 341, 591));
        listWidget->setStyleSheet(QString::fromUtf8("border: 1px solid #ffffff;\n"
"border-radius: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));"));

        retranslateUi(Friends);

        QMetaObject::connectSlotsByName(Friends);
    } // setupUi

    void retranslateUi(QDialog *Friends)
    {
        Friends->setWindowTitle(QCoreApplication::translate("Friends", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Friends: public Ui_Friends {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDS_H
