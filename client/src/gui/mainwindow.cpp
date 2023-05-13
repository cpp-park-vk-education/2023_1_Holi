#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonObject>
#include <QString>
#include <QUrlQuery>
/*VK Settings Auth*/
const QUrl authUrl{"https://oauth.vk.com/authorize"};
const QUrl tokenUrl{"https://oauth.vk.com/access_token"};
const QString clientSecret{"d4rZuR8zHiYHgntXC1kp"};
const QString clientId{"51400815"};
const QString scopeMask = "video"; // https://dev.vk.com/reference/access-rights

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
  oauth->setAccessTokenUrl(tokenUrl);
  oauth->setAuthorizationUrl(authUrl);
  oauth->setClientIdentifier(clientId);
  oauth->setClientIdentifierSharedKey(clientSecret);
  oauth->setScope((scopeMask));
  QObject::connect(oauth, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,
                   &QDesktopServices::openUrl);

  QObject::connect(oauth, &QOAuth2AuthorizationCodeFlow::granted,
                   [oauth, onSuccess, this]() { onSuccess(oauth); });

  QObject::connect(oauth, &QOAuth2AuthorizationCodeFlow::granted, [oauth]() {
    const QUrl getFriends{"https://api.vk.com/method/friends.get"};

    // Vk требует указывать версию API в параметрах запроса. Укажем 5.131
    auto network_reply = oauth->post(getFriends, {{"v", 5.131}});
    QObject::connect(network_reply, &QNetworkReply::finished, [network_reply] {
      //Ответ будет удалён позже, когда отработают все связанные
      //с ним сигнально-слотовые соединения,
      //поэтому такое удаление безопасно
      network_reply->deleteLater();

      QJsonDocument response =
          QJsonDocument::fromJson(network_reply->readAll());
      qDebug() << "All friends ids:";
      for (const auto &user_id : response["response"]["items"].toArray())
        qDebug() << '\t' << user_id.toInteger();
    });
  });
  oauth->grant();
}

QString accessTokenVK;
QOAuth2AuthorizationCodeFlow *oauthVK;
MainWindow::~MainWindow() { delete ui; }

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

void MainWindow::on_YT_Button_clicked() {}

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
  // создаем QNetworkAccessManager
  QNetworkAccessManager manager;

  // создаем объект запроса
  QNetworkRequest request;
  request.setUrl(
      QUrl("https://api.vk.com/method/video.getAlbums")); // замените на
                                                          // соответствующий
                                                          // URL-адрес
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

  // создаем JSON-объект с данными для запроса
  QJsonObject json;
  json.insert("access_token", accessTokenVK);

  QJsonDocument jsonDoc(json);
  QByteArray jsonData = jsonDoc.toJson();

  // отправляем POST-запрос
  QNetworkReply *reply = manager.post(request, jsonData);

  // ждем ответа от сервера
  while (!reply->isFinished()) {
    qDebug() << 1;
    QCoreApplication::processEvents();
  }

  // получаем ответ
  QByteArray response = reply->readAll();

  // обрабатываем ответ (в данном случае это JSON-объект)
  QJsonDocument responseDoc = QJsonDocument::fromJson(response);
  QJsonObject responseObject = responseDoc.object();

  // выводим данные на консоль
  qDebug() << responseObject["resronse"].toString();

  // очищаем память
  reply->deleteLater();
}
