#include "friends.h"
#include "ui_friends.h"

Friends::Friends(QWidget *parent) : QDialog(parent), ui(new Ui::Friends) {
  ui->setupUi(this);
}

Friends::~Friends() { delete ui; }

void Friends::getAllFriends() {}
