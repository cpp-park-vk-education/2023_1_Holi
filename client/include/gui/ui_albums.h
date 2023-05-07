/********************************************************************************
** Form generated from reading UI file 'albums.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALBUMS_H
#define UI_ALBUMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Albums
{
public:
    QGroupBox *groupBox;
    QLabel *Label_Video;
    QLabel *Service;
    QTextBrowser *textBrowser;
    QLabel *IMG;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *Albums)
    {
        if (Albums->objectName().isEmpty())
            Albums->setObjectName(QString::fromUtf8("Albums"));
        Albums->resize(731, 491);
        groupBox = new QGroupBox(Albums);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(400, 10, 281, 471));
        groupBox->setStyleSheet(QString::fromUtf8("border: 1px solid #ffffff;\n"
"border-radius: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));"));
        Label_Video = new QLabel(groupBox);
        Label_Video->setObjectName(QString::fromUtf8("Label_Video"));
        Label_Video->setGeometry(QRect(10, 20, 181, 31));
        Service = new QLabel(groupBox);
        Service->setObjectName(QString::fromUtf8("Service"));
        Service->setGeometry(QRect(10, 60, 181, 16));
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 250, 211, 191));
        IMG = new QLabel(groupBox);
        IMG->setObjectName(QString::fromUtf8("IMG"));
        IMG->setGeometry(QRect(30, 100, 211, 141));
        treeWidget = new QTreeWidget(Albums);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(50, 10, 271, 471));
        treeWidget->setStyleSheet(QString::fromUtf8("border: 1px solid #ffffff;\n"
"border-radius: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.140704 rgba(153, 193, 241, 255), stop:0.894472 rgba(226, 225, 249, 255));"));

        retranslateUi(Albums);

        QMetaObject::connectSlotsByName(Albums);
    } // setupUi

    void retranslateUi(QWidget *Albums)
    {
        Albums->setWindowTitle(QCoreApplication::translate("Albums", "Form", nullptr));
        groupBox->setTitle(QString());
        Label_Video->setText(QCoreApplication::translate("Albums", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        Service->setText(QCoreApplication::translate("Albums", "\320\241\320\265\321\200\320\262\320\270\321\201", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Albums", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\255\321\202\320\276 \320\261\321\203\320\264\320\265\321\202 \320\276\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\262\320\270\320\264\320\276\321\201\320\270\320\272\320\260</p></body></html>", nullptr));
        IMG->setText(QCoreApplication::translate("Albums", "\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Albums", "\320\234\320\276\320\270 \320\262\320\270\320\264\320\265\320\276", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("Albums", "\320\222\320\270\320\264\320\276\321\201\320\270\320\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("Albums", "\320\222\320\270\320\264\320\276\321\201\320\270\320\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("Albums", "\320\222\320\270\320\264\320\276\321\201\320\270\320\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("Albums", "\320\237\320\273\320\265\320\271\320\273\320\270\321\201\321\202", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem4->child(0);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("Albums", "\320\222\320\270\320\264\320\276\321\201\320\270\320\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem4->child(1);
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("Albums", "\320\222\320\270\320\264\320\276\321\201\320\270\320\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem4->child(2);
        ___qtreewidgetitem7->setText(0, QCoreApplication::translate("Albums", "\320\222\320\270\320\264\320\276\321\201\320\270\320\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem4->child(3);
        ___qtreewidgetitem8->setText(0, QCoreApplication::translate("Albums", "\320\222\320\270\320\264\320\276\321\201\320\270\320\272", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class Albums: public Ui_Albums {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALBUMS_H
