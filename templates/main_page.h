#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

#include <QWidget>

namespace Ui {
class Main_page;
}

class Main_page : public QWidget
{
    Q_OBJECT

public:
    explicit Main_page(QWidget *parent = nullptr);
    ~Main_page();

    /*
    Публичные методы для вызова приватных слотов, используются только для тестирования
    */
    void test_private_VK_getAllAlbums(); // Открытый метод
    void test_private_VK_main_import_items(); // Открытый метод
    void test_private_YouTube_getAllAlboms(); // Открытый метод
    void test_private_YouTube_main_import_items(); // Открытый метод

private slots:
    void on_VK_getAllAlboms_clicked();

    void on_VK_main_import_items_clicked();

    void on_YouTube_getAllAlboms_clicked();

    void on_YouTube_main_import_items_clicked();

private:
    Ui::Main_page *ui;
};

#endif // MAIN_PAGE_H
