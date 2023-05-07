/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Config
{
public:
    QPushButton *vk_auth_config;
    QLineEdit *lineEdit_4;
    QListWidget *listWidget_3;
    QPushButton *delete_config;
    QLineEdit *lineEdit_5;
    QLabel *Label_Video_2;
    QPushButton *youtube_auth_config;
    QLabel *Label_Video_3;
    QLineEdit *lineEdit_3;
    QPushButton *save_config;

    void setupUi(QWidget *Config)
    {
        if (Config->objectName().isEmpty())
            Config->setObjectName(QString::fromUtf8("Config"));
        Config->resize(731, 491);
        vk_auth_config = new QPushButton(Config);
        vk_auth_config->setObjectName(QString::fromUtf8("vk_auth_config"));
        vk_auth_config->setGeometry(QRect(20, 140, 121, 30));
        vk_auth_config->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Play"));
        font.setBold(true);
        vk_auth_config->setFont(font);
        vk_auth_config->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEdit_4 = new QLineEdit(Config);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(20, 60, 331, 31));
        lineEdit_4->setStyleSheet(QString::fromUtf8("	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));\n"
"border: 0.5px solid #ffffff;\n"
"border-radius: 10px;"));
        listWidget_3 = new QListWidget(Config);
        new QListWidgetItem(listWidget_3);
        new QListWidgetItem(listWidget_3);
        new QListWidgetItem(listWidget_3);
        new QListWidgetItem(listWidget_3);
        new QListWidgetItem(listWidget_3);
        listWidget_3->setObjectName(QString::fromUtf8("listWidget_3"));
        listWidget_3->setGeometry(QRect(380, 20, 311, 441));
        listWidget_3->setStyleSheet(QString::fromUtf8("	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));\n"
"border: 0.5px solid #ffffff;\n"
"border-radius: 10px;"));
        delete_config = new QPushButton(Config);
        delete_config->setObjectName(QString::fromUtf8("delete_config"));
        delete_config->setGeometry(QRect(170, 430, 181, 30));
        delete_config->setMinimumSize(QSize(0, 30));
        delete_config->setFont(font);
        delete_config->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEdit_5 = new QLineEdit(Config);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(20, 100, 331, 31));
        lineEdit_5->setStyleSheet(QString::fromUtf8("	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));\n"
"border: 0.5px solid #ffffff;\n"
"border-radius: 10px;"));
        Label_Video_2 = new QLabel(Config);
        Label_Video_2->setObjectName(QString::fromUtf8("Label_Video_2"));
        Label_Video_2->setGeometry(QRect(170, 140, 181, 31));
        Label_Video_2->setStyleSheet(QString::fromUtf8("	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));\n"
"border: 0.5px solid #ffffff;\n"
"border-radius: 10px;"));
        youtube_auth_config = new QPushButton(Config);
        youtube_auth_config->setObjectName(QString::fromUtf8("youtube_auth_config"));
        youtube_auth_config->setGeometry(QRect(20, 180, 121, 30));
        youtube_auth_config->setMinimumSize(QSize(0, 30));
        youtube_auth_config->setFont(font);
        youtube_auth_config->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Label_Video_3 = new QLabel(Config);
        Label_Video_3->setObjectName(QString::fromUtf8("Label_Video_3"));
        Label_Video_3->setGeometry(QRect(170, 180, 181, 31));
        Label_Video_3->setStyleSheet(QString::fromUtf8("	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));\n"
"border: 0.5px solid #ffffff;\n"
"border-radius: 10px;"));
        lineEdit_3 = new QLineEdit(Config);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 20, 331, 31));
        lineEdit_3->setStyleSheet(QString::fromUtf8("	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));\n"
"border: 0.5px solid #ffffff;\n"
"border-radius: 10px;"));
        save_config = new QPushButton(Config);
        save_config->setObjectName(QString::fromUtf8("save_config"));
        save_config->setGeometry(QRect(20, 430, 121, 30));
        save_config->setMinimumSize(QSize(0, 30));
        save_config->setFont(font);
        save_config->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(Config);

        QMetaObject::connectSlotsByName(Config);
    } // setupUi

    void retranslateUi(QWidget *Config)
    {
        Config->setWindowTitle(QCoreApplication::translate("Config", "Form", nullptr));
        vk_auth_config->setText(QCoreApplication::translate("Config", "VK", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("Config", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));

        const bool __sortingEnabled = listWidget_3->isSortingEnabled();
        listWidget_3->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_3->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Config", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\277\321\200\320\276\321\204\320\270\320\273\320\265", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_3->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("Config", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217: \320\235\320\260\321\202\320\260\321\210\320\260", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_3->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("Config", "\320\232\320\276\320\273\320\273\320\270\321\207\320\265\321\201\320\272\320\262\320\276 \320\264\321\200\321\203\320\267\320\265\320\271: 50", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_3->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("Config", "\320\232\320\276\320\273\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\320\273\320\265\320\271\320\273\320\270\321\201\321\202\320\276\320\262: 20", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_3->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("Config", "\320\224\320\260\321\202\320\260 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270: 2001", nullptr));
        listWidget_3->setSortingEnabled(__sortingEnabled);

        delete_config->setText(QCoreApplication::translate("Config", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("Config", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        Label_Video_2->setText(QCoreApplication::translate("Config", "\320\241\321\202\320\260\321\202\321\203\321\201/\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        youtube_auth_config->setText(QCoreApplication::translate("Config", "YouTube", nullptr));
        Label_Video_3->setText(QCoreApplication::translate("Config", "\320\241\321\202\320\260\321\202\321\203\321\201/\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("Config", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        save_config->setText(QCoreApplication::translate("Config", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Config: public Ui_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
