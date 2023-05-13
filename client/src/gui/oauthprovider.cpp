#include "oauthprovider.h"
#include "requestmaker.h"
#include <QApplication>
#include <QDesktopServices>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
//#include <QNetworkReply>
#include <QUrl>
#include <QWidget>
#include <QtNetwork/QNetworkReply>
#include <QtNetworkAuth/QAbstractOAuthReplyHandler>
#include <QtNetworkAuth/QOAuth2AuthorizationCodeFlow>
#include <QtNetworkAuth/QOAuthHttpServerReplyHandler>

#include <QUrl>
#include <QWidget>

/*VK Settings*/
const QUrl authUrl{"https://oauth.vk.com/authorize"};
const QUrl tokenUrl{"https://oauth.vk.com/access_token"};
const QString clientSecret{"d4rZuR8zHiYHgntXC1kp"};
const QString clientId{"51400815"};
constexpr quint32 scopeMask = 2; // https://dev.vk.com/reference/access-rights
OAuthProvider::OAuthProvider(QObject *parent) : QObject{parent} {}

QString OAuthProvider::getAccessToken(const QString &serv) {
  QString accessToken;
  if (serv == "vk") {
    accessToken = oAuthVK_getToken();
  } else if (serv == "youtube") {
    //получаем токке доступа Ютуб
  } else {
    return accessToken;
  }
}

QVector<QString> OAuthProvider::getUserProfile(int id_,
                                               const QString &access_token) {
  QVector<QString> result;
  return result;
}

QString OAuthProvider::getAuthorizationUrl(const QString &service) {
  return "";
}

QString OAuthProvider::oAuthVK_getToken() {}
