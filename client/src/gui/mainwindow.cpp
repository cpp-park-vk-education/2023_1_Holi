#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "oauthprovider.h"
#include "client/message_info.h"
#include "api_client/VK/vk_client.hpp"
#include "registrationmanager.h"
#include <QSettings>
#include <QUrlQuery>
#include <QJsonObject>

#include "api_client/YT/yt_client.hpp"

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
/*
ACCESS_TOKEN TEST TEST 0451Nc11
ya29.a0AWY7Ckl7gcpbiTMI_KFmvT7lQSE94JgbqJcUzC-xmw2pblaa8vdsIJ1-s9mRqLUbQp4qMQ5PAt7CjXJRGJFes36C3NLUPUvkug29maSh0ZVHQsCmzKUwAJNS0iaWIpmD9SnDzEl1m2eN3AD6Gpe9G7nOiHNaaCgYKAfUSARESFQG1tDrpY6_exaHWQOCVwcu7KyyiYQ0163
*/
const QUrl authUrlYT{"https://accounts.google.com/o/oauth2/auth"};
const QUrl tokenUrlYT{"https://oauth2.googleapis.com/token"};
const QString clientSecretYT{"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"};
const QString clientIdYT{"869025620327-u6eu9r31nr3p7qdaiqvkgd9g53vtah6q.apps.googleusercontent.com"};
const QString scopeMaskYT = "https://www.googleapis.com/auth/youtube"; // https://dev.vk.com/reference/access-rights
/* VK API Settings*/

QUrl albumsUrl("https://api.vk.com/method/video.getAlbums");

/*\VK API Settings*/

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QSettings current("Holi", "CurrentUser");// это все его настройки
    QString name = current.value("name", "null").toString();
    if (QFile::exists(current.fileName()) && name != "null") {
        ui->statusbar->showMessage(name);
        ui->button_login->hide();
        ui->signUp_button->hide();


    } else {
        ui->logout->hide();
    }
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

    auto oauth = new QOAuth2AuthorizationCodeFlow;
    oauth->setScope((scopeMaskYT));

    QObject::connect(oauth, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,
                     &QDesktopServices::openUrl);

    oauth->setAuthorizationUrl(authUrlYT);
    oauth->setClientIdentifier(clientIdYT);
    oauth->setAccessTokenUrl(tokenUrlYT);
    oauth->setClientIdentifierSharedKey(clientSecretYT);

    oauth->setModifyParametersFunction([this](QAbstractOAuth::Stage stage, QMultiMap<QString, QVariant> *parameters) {
        qDebug() << "modifyParametersFunction stage=" << static_cast<int>(stage);
        if (stage == QAbstractOAuth::Stage::RequestingAuthorization) {
            parameters->insert("access_type", "offline");
            parameters->insert("prompt", "consent");
        } else if (stage == QAbstractOAuth::Stage::RequestingAccessToken) {
            QByteArray code = parameters->value("code").toByteArray();
            QString codeString = QUrl::fromPercentEncoding(code);


            parameters->replace("code", codeString);

        }
    });
    auto replyHandler = new QOAuthHttpServerReplyHandler(4040, this);

    oauth->setReplyHandler(replyHandler);
    oauth->grant();


    QObject::connect(oauth, &QOAuth2AuthorizationCodeFlow::granted,
                     [oauth, onSuccess, this]() {
                         qDebug() << oauth;
                         onSuccess(oauth);
                     });


}

QString accessTokenVK;
QString accessTokenYT;
QOAuth2AuthorizationCodeFlow *oauthVK;

MainWindow::~MainWindow() {
    std::cerr << "mwindow destruct" << std::endl;
    delete ui;
}

/*БОКОВОЕ МЕНЮ*/
void MainWindow::on_main_button_clicked() {
    ui->stackedWidget->setCurrentIndex(0);


}

void MainWindow::on_VK_button_clicked() {
    QSettings current("Holi", "CurrentUser");// это все его настройки
    QString id = current.value("id", "null").toString();
    QSettings settings("Holi", "UserConfig_" + (id));// это все его настройки
    QString token = settings.value("VKAccessToken", "default").toString();//токен
    QDateTime token_getTime = settings.value("VKAccessToken_getTime").toDateTime();//когда получен
    QDateTime now = QDateTime::currentDateTime();//текущее время
    qDebug() << (token == "default" || token_getTime.daysTo(now) >= 1 || !QFile::exists(settings.fileName()));
    if (token == "default" || token_getTime.daysTo(now) >= 1 || !QFile::exists(settings.fileName())) {
        //если прошло больше суток с момента получения токена
        OAuthVK([this](QOAuth2AuthorizationCodeFlow *oauth) {
            qDebug() << oauth->token();

            oauthVK = oauth;
            accessTokenVK = oauth->token();
            int id = 1;
            QDateTime now = QDateTime::currentDateTime();
            QSettings settings("Holi", "UserConfig_" + QString::number(id));
            settings.setValue("VKAccessToken", accessTokenVK);
            settings.setValue("VKAccessToken_getTime", now);
            ui->VK_button->setEnabled(false);
            ui->statusbar->showMessage("Подключен профиль ВКонтакте");
        });
    } else if (token != "default") {
        accessTokenVK = token;
        qDebug() << "Токен из настроек пользователя\nПолучен: " << token_getTime;
        qDebug() << token;

        ui->VK_button->setEnabled(false);
        ui->statusbar->showMessage("Подключен профиль ВКонтакте");
    }

}

void MainWindow::on_YT_Button_clicked() {
    QSettings current("Holi", "CurrentUser");// это все его настройки
    QString id = current.value("id", "null").toString();
    QSettings settings("Holi", "UserConfig_" + (id));// это все его настройки
    QString token = settings.value("YouTubeAccessToken", "default").toString();//токен
    QDateTime token_getTime = settings.value("YouTubeAccessToken_getTime").toDateTime();//когда получен
    QDateTime now = QDateTime::currentDateTime();//текущее время
    qDebug() << (token == "default" || token_getTime.daysTo(now) >= 1 || !QFile::exists(settings.fileName()));
    if (token == "default" || token_getTime.daysTo(now) >= 1 || !QFile::exists(settings.fileName())) {
        OAuthYT([this](QOAuth2AuthorizationCodeFlow *oauth) {
            qDebug() << "swrgwrg";
            qDebug() << oauth->token();
            accessTokenYT = oauth->token();
            int id = 1;
            QDateTime now = QDateTime::currentDateTime();
            QSettings settings("Holi", "UserConfig_" + QString::number(id));
            settings.setValue("YouTubeAccessToken", accessTokenYT);
            settings.setValue("YouTubeAccessToken_getTime", now);
            ui->YT_Button->setEnabled(false);
            ui->statusbar->showMessage("Подключен профиль Ютуб");
        });
    } else if (token != "default") {
        accessTokenYT = token;
        qDebug() << "Токен из настроек пользователя\nПолучен: " << token_getTime;
        qDebug() << token;

        ui->YT_Button->setEnabled(false);
        ui->statusbar->showMessage("Подключен профиль Ютуб");
    }


}

void MainWindow::on_Config_button_clicked() {
    ui->stackedWidget->setCurrentIndex(2);


}

void MainWindow::on_button_login_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_signUp_button_clicked() {
    ui->stackedWidget->setCurrentIndex(4);//Панель регистрации
}

void MainWindow::on_AlbomsButton_clicked() {
    //user = std::make_unique<User>();
    //user->getPlaylistOrChannel(this);
    ui->stackedWidget->setCurrentIndex(3); //страничка с альбомами пользователя
}

void MainWindow::on_VK_getAllAlboms_clicked() {
    std::string token = accessTokenVK.toStdString();
    api_client = std::make_unique<VKClient>(token, 478111331);
    api_client->GetPlaylists(this, 1);
}


struct VKAlbums {
    int id;
    int owner_id;
    QString title;
    QString responseType;
};

QVector<VKAlbums> VK_vec;

//*колбэки для вк*//
void MainWindow::MP_VK_getAlbums(MessageInfo info) {
    ui->VK_main_list_item->clear();
    VK_vec.clear();
    //info содержит статус и json
    std::cout << "Response into GUI" << std::endl;

    std::cout << info << std::endl;
    if (info.status_ == http::status::ok) {
        boost::json::object jsonObject = info.body_.as_object();
        int count = jsonObject["response"].as_object()["count"].as_int64();
        std::cout << "Count: " << count << std::endl;

        boost::json::array itemsArray = jsonObject["response"].as_object()["items"].as_array();
        for (const auto &item: itemsArray) {
            boost::json::object itemObject = item.as_object();
            int id = itemObject["id"].as_int64();
            int ownerId = itemObject["owner_id"].as_int64();
            std::string title = itemObject["title"].as_string().c_str();
            std::string responseType = itemObject["response_type"].as_string().c_str();
            QString res = title.c_str();
            VKAlbums album;
            album.id = id;
            album.owner_id = ownerId;
            album.title = title.c_str();
            album.responseType = responseType.c_str();
            VK_vec.push_back(album);
            ui->VK_main_list_item->addItem(res);
            std::cout << "Item: id=" << id << ", owner_id=" << ownerId
                      << ", title=" << title << ", response_type=" << responseType << std::endl;


        }
        QSettings current("Holi", "CurrentUser");// это все его настройки
        QString id = current.value("id", "null").toString();
        std::cerr << id.toStdString() << std::endl;
        QSettings Playlists("Holi", "Playlist_" + id);
        QStringList list = Playlists.allKeys();
        for (int i = 0; i < list.size(); i++) {
            std::cerr << Playlists.value(list[i]).toInt() << std::endl;
            ui->VK_main_list_item->item(Playlists.value(list[i]).toInt())->setBackground(Qt::red);
        }
    } else {
        QMessageBox msgBox;
        msgBox.setText("Что то пошло не так");
        msgBox.exec();
    }

}

void MainWindow::MP_VK_getVideo(MessageInfo info) {

}

struct YTAlbums {
    QString title;
    QString description;
    QString channelId;
    QString videoId;
};

QVector<YTAlbums> YT_vec;

//*Колбеки для ютуба*//
void MainWindow::MP_YT_getAlbums(MessageInfo info) {
    ui->YouTube_main_list_item->clear();
    YT_vec.clear();
    std::cout << "Got YT Response" << std::endl;
    if (info.status_ == http::status::ok) {

        boost::json::object jsonObject = info.body_.as_object();

        boost::json::array itemsArray = jsonObject["items"].as_array();

        for (const auto &item: itemsArray) {
            QList<QString> playlist;

            boost::json::object itemObject = item.as_object();
            auto elem = itemObject["snippet"];
            auto id = itemObject["id"];
            QString title = elem.as_object()["title"].as_string().c_str();
            QString description = elem.as_object()["description"].as_string().c_str();
            QString channelId = elem.as_object()["channelId"].as_string().c_str();
            QString videoId = id.as_object()["videoId"].as_string().c_str();
            YTAlbums album;
            album.channelId = channelId;
            album.videoId = videoId;
            album.title = title;
            album.description = description;
            YT_vec.push_back(album);
            ui->YouTube_main_list_item->addItem(title);
        }

    } else {
        QMessageBox msgBox;
        msgBox.setText("Что то пошло не так");
        msgBox.exec();

    }

}

void MainWindow::MP_YT_getVideo(MessageInfo info) {

}

void MainWindow::MP_DB_getPC(MessageInfo info) {
    std::cout << "info\n" << info;
}

//Импорт в базу
void MainWindow::on_VK_main_import_items_clicked() {
    std::cout << "on_VK_main_import_items_clicked start" << std::endl;
    user = std::make_unique<User>();
    user->getName(this);
    std::cout << "on_VK_main_import_items_clicked end" << std::endl;
}

//get response
void MainWindow::get_response(MessageInfo info) {
    std::cout << "roigjfb";
    std::cout << info << std::endl;
    QSettings current("Holi", "CurrentUser");// это все его настройки
    QString name = current.value("name", "null").toString();
}

void MainWindow::on_VK_main_list_item_itemDoubleClicked(QListWidgetItem *item) {

    QSettings current("Holi", "CurrentUser");// это все его настройки
    QString id = current.value("id", "null").toString();
    QSettings Playlists("Holi", "Playlist_" + id);
    Playlists.setValue(item->text(), item->listWidget()->row(item));
    std::cout << Playlists.fileName().toStdString();
    std::cout << "Кладем в базу" << std::endl;
    if (!Playlists.allKeys().contains(item->text())) {
        user = std::make_unique<User>();
        user->addPlaylistOrChannel(item->text().toStdString(), "VK", this, item);
        item->setBackground(Qt::red);

    } else {
        ui->statusbar->showMessage(item->text() + " уже добавлен в базу данных");
        item->setBackground(Qt::red);
    }


}

void MainWindow::MP_VK_SuccesfullImportPlaylists(QListWidgetItem *item) {
    std::cout << "srgsrg";
    item->setBackground(Qt::red);
}

void MainWindow::on_YouTube_getAllAlboms_clicked() {
    std::string token = accessTokenYT.toStdString();
    api_client = std::make_unique<YTClient>(token);
    api_client->GetPlaylists(this, 3);
}


/*
 * ===============
SIGNUP РЕГИСТРАЦИЯ
==================
*/


void MainWindow::on_signin_button_clicked() {
    //Создаем менеджер регистрации

    reg = std::make_unique<RegistrationManager>();
    //Получаем данные формы
    QString username = ui->signin_input->text();
    QString email = ui->signin_input_2->text();
    QString password = ui->password_input->text();

    QString username_valid;
    if (reg->isUsernameAvailable(username)) {
        username_valid = "Допустимо";
    } else {
        username_valid = "Недопустимое имя пользователя";
    }

    QString password_valid;
    if (reg->isPasswordValid(password, username, email)) {
        password_valid = "+";
    } else {
        password_valid = "-";
    }

    QString email_valid;
    if (reg->isEmailValid(email)) {
        email_valid = "+";
    } else {
        email_valid = "-";
    }
    if (username.isEmpty() && email.isEmpty() && password.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setText("Не все поля заполнены");
        msgBox.exec();
    }

    bool state = reg->validateUserDetails(username, email, password);

    if (state) {
        reg->registerUser(username, email, password, this);
    } else {
        QMessageBox msgBox;
        QString er = tr("Некорректно подобраны логин, почта или пароль\nИмя "
                        "пользователя: %1\nEmail: %2\nПароль: %3")
                .arg(username_valid, email_valid, password_valid);
        msgBox.setText(er);
        msgBox.exec();
    }
}

void MainWindow::CallBack_Registration(MessageInfo info) {
    boost::json::object jsonObject = info.body_.as_object();
    if (info.status_ == http::status::ok) {
        std::string id = jsonObject["id"].as_string().c_str();
        std::string name = jsonObject["name"].as_string().c_str();
        std::string surname = jsonObject["surname"].as_string().c_str();
        std::string email = jsonObject["email"].as_string().c_str();
        std::string login = jsonObject["login"].as_string().c_str();
        std::string password = jsonObject["password"].as_string().c_str();

        QSettings current("Holi", "CurrentUser");// это все его настройки
        current.setValue("id", id.c_str());
        current.setValue("name", name.c_str());
        current.setValue("surname", surname.c_str());
        current.setValue("email", email.c_str());
        current.setValue("login", login.c_str());
        current.setValue("password", password.c_str());

        qDebug() << current.fileName();

        //ui->stackedWidget->setCurrentIndex(0);
        ui->button_login->hide();
        ui->signUp_button->hide();
        ui->logout->show();
    }

}

void MainWindow::on_logout_clicked() {
    QSettings current("Holi", "CurrentUser");// это все его настройки
    QFile::remove(current.fileName());

}


void MainWindow::on_signin_button_2_clicked() {
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_login_button_clicked() {
    //Тут логика по входу при нажати на войти

    //Получаем данные формы
    QString username = ui->login_input->text(); //Уточнить
    QString password = ui->password_input_2->text();

    user = std::make_unique<User>();
    user->signin(username.toStdString(), password.toStdString(), this);
}

