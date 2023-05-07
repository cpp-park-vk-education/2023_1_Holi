#include "main_page.h"
#include "ui_main_page.h"

Main_page::Main_page(QWidget *parent) : QWidget(parent), ui(new Ui::Main_page) {
  ui->setupUi(this);
}

Main_page::~Main_page() { delete ui; }

/*Обертка из public медотод для тестирования private слотов*/
void Main_page::test_private_VK_getAllAlbums() {
  Main_page::on_VK_getAllAlboms_clicked();
  ui->VK_main_list_item->addItem("1");
}
void Main_page::test_private_YouTube_getAllAlboms() {
  Main_page::on_YouTube_getAllAlboms_clicked();
}
void Main_page::test_private_VK_main_import_items() {
  Main_page::on_VK_main_import_items_clicked();
}
void Main_page::test_private_YouTube_main_import_items() {
  Main_page::on_YouTube_main_import_items_clicked();
}

void Main_page::on_VK_getAllAlboms_clicked() {
  ui->VK_main_list_item->addItem("1");
}

void Main_page::on_VK_main_import_items_clicked() {}

void Main_page::on_YouTube_getAllAlboms_clicked() {}

void Main_page::on_YouTube_main_import_items_clicked() {}
