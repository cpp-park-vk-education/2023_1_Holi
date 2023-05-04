
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_main_button_clicked();

    void on_chat_Button_clicked();

    void on_AlbomsButton_clicked();

    void on_Friends_bar_clicked();

    void on_input_friends_clicked();

    void on_output_friends_clicked();

    void on_VK_button_clicked();

    void on_YT_Button_clicked();

    void on_Config_button_clicked();

    void on_button_login_clicked();

    void on_signUp_button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
