#ifndef CHAT_H
#define CHAT_H

#include <QWidget>

namespace Ui {
class chat;
}

class chat : public QWidget
{
    Q_OBJECT

public:
    explicit chat(QWidget *parent = nullptr);
    ~chat();

private slots:
    void on_button_login_2_clicked();

    void on_send_messege_clicked();

private:
    Ui::chat *ui;
};

#endif // CHAT_H
