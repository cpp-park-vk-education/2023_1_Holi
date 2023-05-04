#include "friends_in.h"
#include "ui_friends_in.h"

Friends_in::Friends_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Friends_in)
{
    ui->setupUi(this);
}

Friends_in::~Friends_in()
{
    delete ui;
}

void Friends_in::on_accept_clicked()
{

}


void Friends_in::on_cancel_clicked()
{

}

void Friends_in::getInRequest(){

}
