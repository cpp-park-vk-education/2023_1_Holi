#include "chat.h"
#include "ui_chat.h"

chat::chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
}

chat::~chat()
{
    delete ui;
}


void chat::on_send_messege_clicked()
{

}

