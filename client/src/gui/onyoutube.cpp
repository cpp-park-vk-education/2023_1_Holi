#include "onyoutube.h"
#include "ui_onyoutube.h"
onYouTube::onYouTube(QWidget *parent) : QWidget(parent), ui(new Ui::onYouTube) {
  ui->setupUi(this);
}

onYouTube::~onYouTube() { delete ui; }

void onYouTube::on_auth_YouTube_clicked() {}
