#include "onvk.h"
#include "ui_onvk.h"

onVK::onVK(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::onVK)
{
    ui->setupUi(this);
}

onVK::~onVK()
{
    delete ui;
}

void onVK::on_auth_VK_clicked()
{

}

