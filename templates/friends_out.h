#ifndef FRIENDS_OUT_H
#define FRIENDS_OUT_H

#include <QDialog>

namespace Ui {
class Friends_out;
}

class Friends_out : public QDialog
{
    Q_OBJECT

public:
    explicit Friends_out(QWidget *parent = nullptr);
    ~Friends_out();

private slots:
    void on_cancel_request_clicked();

private:
    Ui::Friends_out *ui;

    void getOutRequest();
};

#endif // FRIENDS_OUT_H
