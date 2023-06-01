#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "api_client/Base/client.hpp"
#include "oauthprovider.h"

#include <QMessageBox>
#include <QMainWindow>
#include <QApplication>
#include <QDesktopServices>
#include <QFile>
#include <QJsonArray>
#include <QListWidget>
#include <QListWidgetItem>
#include <QJsonDocument>
#include <memory>

#include <QtNetwork/QNetworkReply>
#include <QtNetworkAuth/QAbstractOAuthReplyHandler>
#include <QtNetworkAuth/QOAuth2AuthorizationCodeFlow>

#include <QUrl>
#include <QWidget>


#include "registrationmanager.h"

#include <chrono>

#include <memory>


QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class APIClient;

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void OAuthVK(const std::function<void(QOAuth2AuthorizationCodeFlow *)> &onSuccess);

    void OAuthYT(const std::function<void(QOAuth2AuthorizationCodeFlow *)> &onSuccess);
    /*Callback Methods*/

    /*mainpage*/
    /*колбэки для вк*/
    void MP_VK_getAlbums(MessageInfo info);

    void MP_VK_getVideo(MessageInfo info);

    void MP_VK_SuccesfullImportPlaylists(QListWidgetItem *item);
    /*Колбеки для ютуба*/
    void MP_YT_getAlbums(MessageInfo info);

    void MP_YT_getVideo(MessageInfo info);

    void MP_YT_checkAddPlaylis(MessageInfo info);
    //
    void MP_addPlaylis_YouTube(MessageInfo info);

    void get_response(MessageInfo info);
    //
    void CallBack_Registration(MessageInfo info);

    void MP_DB_getPC(MessageInfo info);
private slots:

    void on_main_button_clicked();

    void on_AlbomsButton_clicked();

    void on_VK_button_clicked();

    void on_YT_Button_clicked();

    void on_Config_button_clicked();

    void on_button_login_clicked();

    void on_signUp_button_clicked();

    void on_VK_getAllAlboms_clicked();

    void on_VK_main_list_item_itemDoubleClicked(QListWidgetItem *item);

    void on_YouTube_getAllAlboms_clicked();

    void on_signin_button_clicked();



    void on_logout_clicked();

    void on_signin_button_2_clicked();

    void on_login_button_clicked();

    void on_YouTube_main_list_item_itemDoubleClicked(QListWidgetItem *item);



private:
    Ui::MainWindow *ui;
    std::unique_ptr<APIClient> api_client;
    std::unique_ptr<User> user;
    std::unique_ptr<RegistrationManager> reg;


};

#endif // MAINWINDOW_H
