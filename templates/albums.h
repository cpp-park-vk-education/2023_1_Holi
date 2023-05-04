#ifndef ALBUMS_H
#define ALBUMS_H

#include <QWidget>
#include <QTreeWidget>
#include <QUrl>
#include <QDesktopServices>


namespace Ui {
class Albums;
}

class Albums : public QWidget
{
    Q_OBJECT

public:
    explicit Albums(QWidget *parent = nullptr);
    ~Albums();

    void test_doubleClick();
    void test_click();
    QString Test();
private slots:
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);


private:
    Ui::Albums *ui;
};

#endif // ALBUMS_H
