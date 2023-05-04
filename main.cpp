
#include "mainwindow.h"
//#include <QOAuth2AuthorizationCodeFlow>
//#include <QOAuthHttpServerReplyHandler>
//#include <QDesktopServices>
//#include <QNetworkReply>
//#include <QJsonDocument>
//#include <QApplication>
//#include <QJsonArray>
//#include <QWidget>
//#include <QFile>
//#include <QUrl>
#include <QApplication>
//const QUrl authUrl{ "https://oauth.vk.com/authorize" };
//const QUrl tokenUrl{ "https://oauth.vk.com/access_token" };
//const QString clientSecret{ "3vSSIid8r9p6nIo7jauy" };
//const QString clientId{ "51601721" };
//constexpr quint32 scopeMask = 2;//https://dev.vk.com/reference/access-rights



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;




   /* auto oauth = new QOAuth2AuthorizationCodeFlow(&w);
    auto replyHandler = new QOAuthHttpServerReplyHandler(6543, &w);


    oauth->setReplyHandler(replyHandler);
    oauth->setAccessTokenUrl(tokenUrl);
    oauth->setAuthorizationUrl(authUrl);
    oauth->setClientIdentifier(clientId);
    oauth->setClientIdentifierSharedKey(clientSecret);
    oauth->setScope(QString::number(scopeMask));
    QObject::connect(oauth, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, &QDesktopServices::openUrl);

    QObject::connect(oauth, &QOAuth2AuthorizationCodeFlow::statusChanged,
                     [&](QAbstractOAuth::Status status) {
                         if (status == QAbstractOAuth::Status::Granted) {
                             qDebug() << "Token granted:" << oauth->token().toStdString().c_str();
                            // a.quit();
                         }
                     });

    oauth->grant();*/

    w.show();
    return a.exec();
}



