/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat
{
public:
    QLineEdit *lineEdit_2;
    QPushButton *send_messege;
    QListWidget *listWidget;
    QListWidget *listWidget_2;

    void setupUi(QWidget *chat)
    {
        if (chat->objectName().isEmpty())
            chat->setObjectName(QString::fromUtf8("chat"));
        chat->resize(731, 491);
        lineEdit_2 = new QLineEdit(chat);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(250, 420, 331, 31));
        lineEdit_2->setStyleSheet(QString::fromUtf8("	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));\n"
"border: 0.5px solid #ffffff;\n"
"border-radius: 10px;"));
        send_messege = new QPushButton(chat);
        send_messege->setObjectName(QString::fromUtf8("send_messege"));
        send_messege->setGeometry(QRect(590, 420, 111, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Play"));
        font.setBold(true);
        send_messege->setFont(font);
        send_messege->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        listWidget = new QListWidget(chat);
        new QListWidgetItem(listWidget);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../vks/static/svg/VK.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem->setIcon(icon);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem1->setIcon(icon);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem2->setIcon(icon);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem3->setIcon(icon);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 50, 201, 361));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Play"));
        font1.setPointSize(14);
        listWidget->setFont(font1);
        listWidget->setStyleSheet(QString::fromUtf8("QListView{\n"
"	\n"
"	color: rgb(53, 132, 228);\n"
"border: 1px solid #ffffff;\n"
"border-radius: 5px;\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(153, 193, 241, 255), stop:1 rgba(220, 138, 221, 255));\n"
"}"));
        listWidget_2 = new QListWidget(chat);
        QBrush brush(QColor(226, 225, 249, 255));
        brush.setStyle(Qt::NoBrush);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem4->setBackground(brush);
        __qlistwidgetitem4->setIcon(icon);
        __qlistwidgetitem4->setFlags(Qt::ItemIsEnabled);
        new QListWidgetItem(listWidget_2);
        QBrush brush1(QColor(255, 206, 206, 255));
        brush1.setStyle(Qt::SolidPattern);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem5->setBackground(brush1);
        __qlistwidgetitem5->setIcon(icon);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem6->setBackground(brush1);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(250, 50, 451, 361));
        listWidget_2->setStyleSheet(QString::fromUtf8("border: 1px solid #ffffff;\n"
"border-radius: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));"));
        listWidget_2->setProperty("showDropIndicator", QVariant(false));
        listWidget_2->setDragEnabled(false);
        listWidget_2->setDragDropOverwriteMode(false);
        listWidget_2->setAlternatingRowColors(false);
        listWidget_2->setTextElideMode(Qt::ElideRight);
        listWidget_2->setMovement(QListView::Static);
        listWidget_2->setFlow(QListView::TopToBottom);
        listWidget_2->setProperty("isWrapping", QVariant(false));
        listWidget_2->setUniformItemSizes(false);
        listWidget_2->setBatchSize(200);

        retranslateUi(chat);

        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QWidget *chat)
    {
        chat->setWindowTitle(QCoreApplication::translate("chat", "Form", nullptr));
        send_messege->setText(QCoreApplication::translate("chat", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(1);
        ___qlistwidgetitem->setText(QCoreApplication::translate("chat", "\320\235\320\260\321\202\320\260\321\210\320\260 \320\240\320\276\321\201\321\202\320\276\320\262\320\260", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(2);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("chat", "\320\233\320\265\320\262 \320\242\320\276\320\273\321\201\321\202\320\276\320\271", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(3);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("chat", "\320\237\321\214\320\265\321\200 \320\221\320\265\320\267\321\203\321\205\320\276\320\262", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(4);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("chat", "\320\255\320\273\320\265\320\275 \320\232\321\203\321\200\320\260\320\263\320\270\320\275\320\260", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);


        const bool __sortingEnabled1 = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem4 = listWidget_2->item(0);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("chat", "\320\237\321\200\320\270\320\262\320\265\321\202", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget_2->item(1);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("chat", "\320\232\320\260\320\272 \320\264\320\265\320\273\320\260?", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget_2->item(2);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("chat", "\320\225\321\211\320\265 \320\275\320\265 \321\200\320\276\320\264\320\270\320\273\320\260", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = listWidget_2->item(3);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("chat", "\320\237\320\276\320\272\320\260!", nullptr));
        listWidget_2->setSortingEnabled(__sortingEnabled1);

    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
