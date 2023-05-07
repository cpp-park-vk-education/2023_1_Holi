/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QStackedWidget *stackedWidget;
    QWidget *verticalWidget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *main_button;
    QPushButton *chat_Button;
    QPushButton *AlbomsButton;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QPushButton *Friends_bar;
    QPushButton *input_friends;
    QPushButton *output_friends;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QPushButton *VK_button;
    QPushButton *YT_Button;
    QPushButton *Config_button;
    QSpacerItem *verticalSpacer_3;
    QPushButton *button_login;
    QPushButton *signUp_button;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(952, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(167, 62, 231, 255), stop:1 rgba(0, 235, 255, 255));\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(180, -20, 20, 601));
        line->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:1 rgba(0, 0, 0, 0));"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setEnabled(true);
        stackedWidget->setGeometry(QRect(190, 20, 731, 491));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:1 rgba(0, 0, 0, 0));"));
        verticalWidget_2 = new QWidget(centralwidget);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        verticalWidget_2->setGeometry(QRect(10, 80, 160, 451));
        verticalWidget_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:1 rgba(0, 0, 0, 0));"));
        verticalLayout_3 = new QVBoxLayout(verticalWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        main_button = new QPushButton(verticalWidget_2);
        main_button->setObjectName(QString::fromUtf8("main_button"));
        main_button->setMinimumSize(QSize(62, 19));
        QFont font;
        font.setFamily(QString::fromUtf8("Play"));
        font.setPointSize(12);
        main_button->setFont(font);
        main_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
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

        verticalLayout_3->addWidget(main_button, 0, Qt::AlignLeft);

        chat_Button = new QPushButton(verticalWidget_2);
        chat_Button->setObjectName(QString::fromUtf8("chat_Button"));
        chat_Button->setFont(font);
        chat_Button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
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

        verticalLayout_3->addWidget(chat_Button, 0, Qt::AlignLeft);

        AlbomsButton = new QPushButton(verticalWidget_2);
        AlbomsButton->setObjectName(QString::fromUtf8("AlbomsButton"));
        AlbomsButton->setFont(font);
        AlbomsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
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

        verticalLayout_3->addWidget(AlbomsButton, 0, Qt::AlignLeft);

        verticalSpacer = new QSpacerItem(155, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        label_4 = new QLabel(verticalWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Play"));
        font1.setPointSize(12);
        font1.setBold(true);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(232, 231, 255);\n"
""));

        verticalLayout_3->addWidget(label_4);

        Friends_bar = new QPushButton(verticalWidget_2);
        Friends_bar->setObjectName(QString::fromUtf8("Friends_bar"));
        Friends_bar->setFont(font);
        Friends_bar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
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

        verticalLayout_3->addWidget(Friends_bar, 0, Qt::AlignLeft);

        input_friends = new QPushButton(verticalWidget_2);
        input_friends->setObjectName(QString::fromUtf8("input_friends"));
        input_friends->setFont(font);
        input_friends->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
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

        verticalLayout_3->addWidget(input_friends, 0, Qt::AlignLeft);

        output_friends = new QPushButton(verticalWidget_2);
        output_friends->setObjectName(QString::fromUtf8("output_friends"));
        output_friends->setFont(font);
        output_friends->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
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

        verticalLayout_3->addWidget(output_friends, 0, Qt::AlignLeft);

        verticalSpacer_2 = new QSpacerItem(155, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        label_3 = new QLabel(verticalWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(232, 231, 255);\n"
""));

        verticalLayout_3->addWidget(label_3);

        VK_button = new QPushButton(verticalWidget_2);
        VK_button->setObjectName(QString::fromUtf8("VK_button"));
        VK_button->setFont(font);
        VK_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
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

        verticalLayout_3->addWidget(VK_button, 0, Qt::AlignLeft);

        YT_Button = new QPushButton(verticalWidget_2);
        YT_Button->setObjectName(QString::fromUtf8("YT_Button"));
        YT_Button->setFont(font);
        YT_Button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
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

        verticalLayout_3->addWidget(YT_Button, 0, Qt::AlignLeft);

        Config_button = new QPushButton(verticalWidget_2);
        Config_button->setObjectName(QString::fromUtf8("Config_button"));
        Config_button->setFont(font);
        Config_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
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

        verticalLayout_3->addWidget(Config_button, 0, Qt::AlignLeft);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        button_login = new QPushButton(verticalWidget_2);
        button_login->setObjectName(QString::fromUtf8("button_login"));
        button_login->setMinimumSize(QSize(0, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Play"));
        font2.setBold(true);
        button_login->setFont(font2);
        button_login->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout_3->addWidget(button_login);

        signUp_button = new QPushButton(verticalWidget_2);
        signUp_button->setObjectName(QString::fromUtf8("signUp_button"));
        signUp_button->setMinimumSize(QSize(0, 30));
        signUp_button->setFont(font2);
        signUp_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"\n"
""));

        verticalLayout_3->addWidget(signUp_button);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 161, 91));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Play"));
        font3.setPointSize(44);
        font3.setBold(true);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(232, 231, 255);\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 952, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        main_button->setText(QCoreApplication::translate("MainWindow", "\320\223\320\273\320\260\320\262\320\275\320\260\321\217", nullptr));
        chat_Button->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\201\321\201\320\265\320\275\320\264\320\266\320\265\321\200", nullptr));
        AlbomsButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\270 \320\260\320\273\321\214\320\261\320\276\320\274\321\213", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\276\320\261\321\211\320\265\321\201\321\202\320\262\320\276", nullptr));
        Friends_bar->setText(QCoreApplication::translate("MainWindow", "\320\224\321\200\321\203\320\267\321\214\321\217", nullptr));
        input_friends->setText(QCoreApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264\321\217\321\211\320\270\320\265 \320\267\320\260\321\217\320\262\320\272\320\270", nullptr));
        output_friends->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\321\217\321\211\320\270\320\265 \320\267\320\260\321\217\320\262\320\272\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\321\200\320\262\320\270\321\201\321\213", nullptr));
        VK_button->setText(QCoreApplication::translate("MainWindow", "VK", nullptr));
        YT_Button->setText(QCoreApplication::translate("MainWindow", "YouTube", nullptr));
        Config_button->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        button_login->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        signUp_button->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "HOLI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
