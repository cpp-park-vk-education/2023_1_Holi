/********************************************************************************
** Form generated from reading UI file 'main_page.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_PAGE_H
#define UI_MAIN_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main_page
{
public:
    QPushButton *VK_getAllAlboms;
    QPushButton *YouTube_getAllAlboms;
    QComboBox *VK_main_playists;
    QListWidget *YouTube_main_list_item;
    QListWidget *VK_main_list_item;
    QComboBox *YouTube_main_playists;
    QComboBox *VK_main_type_request;
    QComboBox *YouTube_main_type_request;
    QPushButton *YouTube_main_import_items;
    QPushButton *VK_main_import_items;

    void setupUi(QWidget *Main_page)
    {
        if (Main_page->objectName().isEmpty())
            Main_page->setObjectName(QString::fromUtf8("Main_page"));
        Main_page->resize(731, 491);
        VK_getAllAlboms = new QPushButton(Main_page);
        VK_getAllAlboms->setObjectName(QString::fromUtf8("VK_getAllAlboms"));
        VK_getAllAlboms->setGeometry(QRect(20, 10, 71, 25));
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
        YouTube_getAllAlboms = new QPushButton(Main_page);
        YouTube_getAllAlboms->setObjectName(QString::fromUtf8("YouTube_getAllAlboms"));
        YouTube_getAllAlboms->setGeometry(QRect(350, 10, 81, 25));
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
        VK_main_playists = new QComboBox(Main_page);
        VK_main_playists->setObjectName(QString::fromUtf8("VK_main_playists"));
        VK_main_playists->setGeometry(QRect(190, 10, 111, 22));
        YouTube_main_list_item = new QListWidget(Main_page);
        new QListWidgetItem(YouTube_main_list_item);
        new QListWidgetItem(YouTube_main_list_item);
        new QListWidgetItem(YouTube_main_list_item);
        new QListWidgetItem(YouTube_main_list_item);
        new QListWidgetItem(YouTube_main_list_item);
        new QListWidgetItem(YouTube_main_list_item);
        new QListWidgetItem(YouTube_main_list_item);
        new QListWidgetItem(YouTube_main_list_item);
        new QListWidgetItem(YouTube_main_list_item);
        new QListWidgetItem(YouTube_main_list_item);
        YouTube_main_list_item->setObjectName(QString::fromUtf8("YouTube_main_list_item"));
        YouTube_main_list_item->setGeometry(QRect(350, 40, 281, 411));
        YouTube_main_list_item->setStyleSheet(QString::fromUtf8("border: 1px solid #ffffff;\n"
"border-radius: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));"));
        VK_main_list_item = new QListWidget(Main_page);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(VK_main_list_item);
        __qlistwidgetitem->setCheckState(Qt::Unchecked);
        __qlistwidgetitem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(VK_main_list_item);
        __qlistwidgetitem1->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(VK_main_list_item);
        __qlistwidgetitem2->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(VK_main_list_item);
        __qlistwidgetitem3->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(VK_main_list_item);
        __qlistwidgetitem4->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(VK_main_list_item);
        __qlistwidgetitem5->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(VK_main_list_item);
        __qlistwidgetitem6->setCheckState(Qt::Unchecked);
        VK_main_list_item->setObjectName(QString::fromUtf8("VK_main_list_item"));
        VK_main_list_item->setGeometry(QRect(20, 40, 281, 411));
        VK_main_list_item->setStyleSheet(QString::fromUtf8(""));
        YouTube_main_playists = new QComboBox(Main_page);
        YouTube_main_playists->setObjectName(QString::fromUtf8("YouTube_main_playists"));
        YouTube_main_playists->setGeometry(QRect(530, 10, 101, 22));
        YouTube_main_playists->setEditable(false);
        VK_main_type_request = new QComboBox(Main_page);
        VK_main_type_request->addItem(QString());
        VK_main_type_request->addItem(QString());
        VK_main_type_request->setObjectName(QString::fromUtf8("VK_main_type_request"));
        VK_main_type_request->setGeometry(QRect(100, 10, 81, 22));
        YouTube_main_type_request = new QComboBox(Main_page);
        YouTube_main_type_request->addItem(QString());
        YouTube_main_type_request->addItem(QString());
        YouTube_main_type_request->setObjectName(QString::fromUtf8("YouTube_main_type_request"));
        YouTube_main_type_request->setGeometry(QRect(440, 10, 81, 22));
        YouTube_main_import_items = new QPushButton(Main_page);
        YouTube_main_import_items->setObjectName(QString::fromUtf8("YouTube_main_import_items"));
        YouTube_main_import_items->setGeometry(QRect(350, 460, 71, 25));
        YouTube_main_import_items->setContextMenuPolicy(Qt::NoContextMenu);
        YouTube_main_import_items->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        VK_main_import_items = new QPushButton(Main_page);
        VK_main_import_items->setObjectName(QString::fromUtf8("VK_main_import_items"));
        VK_main_import_items->setGeometry(QRect(20, 460, 71, 25));
        VK_main_import_items->setContextMenuPolicy(Qt::NoContextMenu);
        VK_main_import_items->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(Main_page);

        QMetaObject::connectSlotsByName(Main_page);
    } // setupUi

    void retranslateUi(QWidget *Main_page)
    {
        Main_page->setWindowTitle(QCoreApplication::translate("Main_page", "Form", nullptr));
        VK_getAllAlboms->setText(QCoreApplication::translate("Main_page", "\320\222\320\232", nullptr));
        YouTube_getAllAlboms->setText(QCoreApplication::translate("Main_page", "YouTube", nullptr));

        const bool __sortingEnabled = YouTube_main_list_item->isSortingEnabled();
        YouTube_main_list_item->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = YouTube_main_list_item->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = YouTube_main_list_item->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = YouTube_main_list_item->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = YouTube_main_list_item->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = YouTube_main_list_item->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = YouTube_main_list_item->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = YouTube_main_list_item->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = YouTube_main_list_item->item(7);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = YouTube_main_list_item->item(8);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = YouTube_main_list_item->item(9);
        ___qlistwidgetitem9->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        YouTube_main_list_item->setSortingEnabled(__sortingEnabled);


        const bool __sortingEnabled1 = VK_main_list_item->isSortingEnabled();
        VK_main_list_item->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem10 = VK_main_list_item->item(0);
        ___qlistwidgetitem10->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QListWidgetItem *___qlistwidgetitem11 = VK_main_list_item->item(1);
        ___qlistwidgetitem11->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QListWidgetItem *___qlistwidgetitem12 = VK_main_list_item->item(2);
        ___qlistwidgetitem12->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QListWidgetItem *___qlistwidgetitem13 = VK_main_list_item->item(3);
        ___qlistwidgetitem13->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QListWidgetItem *___qlistwidgetitem14 = VK_main_list_item->item(4);
        ___qlistwidgetitem14->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QListWidgetItem *___qlistwidgetitem15 = VK_main_list_item->item(5);
        ___qlistwidgetitem15->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QListWidgetItem *___qlistwidgetitem16 = VK_main_list_item->item(6);
        ___qlistwidgetitem16->setText(QCoreApplication::translate("Main_page", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        VK_main_list_item->setSortingEnabled(__sortingEnabled1);

        VK_main_type_request->setItemText(0, QCoreApplication::translate("Main_page", "\320\220\320\273\321\214\320\261\320\276\320\274\321\213", nullptr));
        VK_main_type_request->setItemText(1, QCoreApplication::translate("Main_page", "\320\222\320\270\320\264\320\265\320\276", nullptr));

        YouTube_main_type_request->setItemText(0, QCoreApplication::translate("Main_page", "\320\220\320\273\321\214\320\261\320\276\320\274\321\213", nullptr));
        YouTube_main_type_request->setItemText(1, QCoreApplication::translate("Main_page", "\320\222\320\270\320\264\320\265\320\276", nullptr));

        YouTube_main_import_items->setText(QCoreApplication::translate("Main_page", "\320\230\320\274\320\277\320\276\321\200\321\202", nullptr));
        VK_main_import_items->setText(QCoreApplication::translate("Main_page", "\320\230\320\274\320\277\320\276\321\200\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Main_page: public Ui_Main_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_PAGE_H
