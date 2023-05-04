#include "friends_out.h"
#include "ui_friends_out.h"

Friends_out::Friends_out(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Friends_out)
{
    ui->setupUi(this);
    Friends_out::getOutRequest();
}

Friends_out::~Friends_out()
{
    delete ui;
}

void Friends_out::on_cancel_request_clicked()
{

}

void Friends_out::getOutRequest(){
    qDebug() << "ahfbvsfavn";
}
