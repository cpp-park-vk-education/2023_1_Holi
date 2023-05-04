#include "albums.h"
#include "ui_albums.h"

Albums::Albums(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Albums)
{
    ui->setupUi(this);
}

Albums::~Albums()
{
    delete ui;
}

void Albums::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    QString urlStr = "https://dev.vk.com/method/video.get";

    // Открываем ссылку в браузере
    QDesktopServices::openUrl(QUrl(urlStr));
}


void Albums::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{

}

void Albums::test_click(){
   // Albums::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
}

QString Albums::Test(){
    return "12345";
}
