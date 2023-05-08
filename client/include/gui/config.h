#ifndef CONFIG_H
#define CONFIG_H

#include <QWidget>

namespace Ui {
class Config;
}

class Config : public QWidget {
  Q_OBJECT

public:
  explicit Config(QWidget *parent = nullptr);
  ~Config();

private slots:
  void on_vk_auth_config_clicked();

  void on_youtube_auth_config_clicked();

  void on_save_config_clicked();

  void on_delete_config_clicked();

private:
  Ui::Config *ui;
};

#endif // CONFIG_H
