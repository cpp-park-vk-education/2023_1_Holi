#ifndef ONYOUTUBE_H
#define ONYOUTUBE_H

#include <QWidget>

namespace Ui {
class onYouTube;
}

class onYouTube : public QWidget
{
    Q_OBJECT

public:
    explicit onYouTube(QWidget *parent = nullptr);
    ~onYouTube();

private slots:
    void on_auth_YouTube_clicked();

private:
    Ui::onYouTube *ui;
};

#endif // ONYOUTUBE_H
