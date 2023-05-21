#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "oauthprovider.h"
#include "client/message_info.h"
#include "api_client/VK/vk_client.hpp"

#include <chrono>
#include <memory>
//#include <boost/json/src.hpp>
/*VK Settings Auth*/
const QUrl authUrlVK{"https://oauth.vk.com/authorize"};
const QUrl tokenUrlVK{"https://oauth.vk.com/access_token"};
const QString clientSecretVK{"d4rZuR8zHiYHgntXC1kp"};
const QString clientIdVK{"51400815"};
const QString scopeMaskVK = "video"; // https://dev.vk.com/reference/access-rights


/*YT Settings Auth*/
const QUrl authUrlYT{"https://accounts.google.com/o/oauth2/auth"};
const QUrl tokenUrlYT{"https://oauth2.googleapis.com/token"};
const QString clientSecretYT{"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"};
const QString clientIdYT{"869025620327-u6eu9r31nr3p7qdaiqvkgd9g53vtah6q.apps.googleusercontent.com"};
const QString scopeMaskYT = "video"; // https://dev.vk.com/reference/access-rights
/* VK API Settings*/

QUrl albumsUrl("https://api.vk.com/method/video.getAlbums");

/*\VK API Settings*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->statusbar->showMessage("Имя Пользователя");
}

void MainWindow::OAuthVK(
    const std::function<void(QOAuth2AuthorizationCodeFlow *)> &onSuccess) {
  auto oauth = new QOAuth2AuthorizationCodeFlow;
  auto replyHandler = new QOAuthHttpServerReplyHandler(6543, this);

  oauth->setReplyHandler(replyHandler);
  oauth->setAccessTokenUrl(tokenUrlVK);
  oauth->setAuthorizationUrl(authUrlVK);
  oauth->setClientIdentifier(clientIdVK);
  oauth->setClientIdentifierSharedKey(clientSecretVK);
  oauth->setScope((scopeMaskVK));
  QObject::connect(oauth, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,
                   &QDesktopServices::openUrl);

  QObject::connect(oauth, &QOAuth2AuthorizationCodeFlow::granted,
                   [oauth, onSuccess, this]() { onSuccess(oauth); });
  oauth->grant();
}


//Метод авторизации в YT
void MainWindow::OAuthYT(
    const std::function<void(QOAuth2AuthorizationCodeFlow *)> &onSuccess) {



    GoogleAuth googleAuth;

}

QString accessTokenVK;
QString accessTokenYT;
QOAuth2AuthorizationCodeFlow *oauthVK;

MainWindow::~MainWindow() {
    std::cerr << "mwindow destruct" << std::endl;
    delete ui; }

/*БОКОВОЕ МЕНЮ*/
void MainWindow::on_main_button_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_VK_button_clicked() {
  OAuthVK([this](QOAuth2AuthorizationCodeFlow *oauth) {
    qDebug() << oauth->token();

    oauthVK = oauth;
    accessTokenVK = oauth->token();
    ui->VK_button->setEnabled(false);
    ui->statusbar->showMessage("Подключен профиль ВКонтакте");
  });
}

void MainWindow::on_YT_Button_clicked() {
    boost::json::value j = boost::json::parse(R"(
    {
        "name": "Name",
        "image": "image"
    }
    )");

    boost::json::object obj = j.as_object();

    qDebug() << obj["name"].as_string().c_str();

    ui->VK_main_list_item->addItem(obj["name"].as_string().c_str());
}

void MainWindow::on_Config_button_clicked() {
  ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_button_login_clicked() {
  Login dialog;
  dialog.setModal(true);
  dialog.exec();
}

void MainWindow::on_signUp_button_clicked() {
  SignUp dialog;
  dialog.setModal(true);
  dialog.exec();
}

void MainWindow::on_AlbomsButton_clicked() {
  ui->stackedWidget->setCurrentIndex(2); //страничка с альбомами пользователя
}

void MainWindow::on_VK_getAllAlboms_clicked() {
    std::string token = accessTokenVK.toStdString();
    std::cout << "99" << std::endl;
    api_client = std::make_unique<VKClient>(token, 478111331);
    api_client->GetPlaylists(this, 1);

    std::cout << "100" << std::endl;
}


//*колбэки для вк*//
void MainWindow::MP_VK_getAlbums(MessageInfo info){
    //info содержит статус и json
    std::cout << "Response into GUI" << std::endl;
    std::cout << info << std::endl;
}

void MainWindow::MP_VK_getVideo(MessageInfo info){

}

//*Колбеки для ютуба*//
void MainWindow::MP_YT_getAlbums(MessageInfo info){

}

void MainWindow::MP_YT_getVideo(MessageInfo info){

}


//Импорт в базу
void MainWindow::on_VK_main_import_items_clicked()
{
    //QString strToBase = "C++";
}

//get response
void MainWindow::get_response(MessageInfo info)
{
  std::cout<<info<<std::endl;
}