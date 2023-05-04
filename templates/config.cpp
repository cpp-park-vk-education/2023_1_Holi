#include "config.h"
#include "ui_config.h"

Config::Config(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Config)
{
    ui->setupUi(this);
}

Config::~Config()
{
    delete ui;
}

void Config::on_vk_auth_config_clicked()
{

}


void Config::on_youtube_auth_config_clicked()
{

}


void Config::on_save_config_clicked()
{

}


void Config::on_delete_config_clicked()
{

}

