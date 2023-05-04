#ifndef FRIENDS_H
#define FRIENDS_H

#include <QDialog>

namespace Ui {
class Friends;
}

class Friends : public QDialog
{
    Q_OBJECT

public:
    explicit Friends(QWidget *parent = nullptr);
    ~Friends();

private:
    Ui::Friends *ui;

    void getAllFriends();

};

#endif // FRIENDS_H
