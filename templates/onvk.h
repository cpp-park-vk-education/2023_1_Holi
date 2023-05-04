#ifndef ONVK_H
#define ONVK_H

#include <QWidget>

namespace Ui {
class onVK;
}

class onVK : public QWidget
{
    Q_OBJECT

public:
    explicit onVK(QWidget *parent = nullptr);
    ~onVK();

private slots:
    void on_auth_VK_clicked();

private:
    Ui::onVK *ui;
};

#endif // ONVK_H
