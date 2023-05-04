#ifndef FRIENDS_IN_H
#define FRIENDS_IN_H

#include <QDialog>

namespace Ui {
class Friends_in;
}

class Friends_in : public QDialog
{
    Q_OBJECT

public:
    explicit Friends_in(QWidget *parent = nullptr);
    ~Friends_in();

private slots:
    void on_accept_clicked();

    void on_cancel_clicked();

private:
    Ui::Friends_in *ui;

    void getInRequest();
};

#endif // FRIENDS_IN_H
