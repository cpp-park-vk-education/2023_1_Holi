#ifndef OAUTHPROVIDER_H
#define OAUTHPROVIDER_H

#include <QDebug>
#include <QDesktopServices>
#include <QFile>
#include <QJsonDocument>
#include <QtNetworkAuth/QOAuth2AuthorizationCodeFlow>
#include <QtNetworkAuth/QOAuthHttpServerReplyHandler>
//#include <QOAuth2AuthorizationCodeFlow>
//#include <QOAuthHttpServerReplyHandler>

#include <QObject>
#include <QUrl>

class OAuthProvider : public QObject {
  Q_OBJECT
public:
  explicit OAuthProvider(QObject *parent = nullptr);
  QString getAccessToken(const QString &); //получить токен доступа
  QVector<QString> getUserProfile(int id, const QString &); //получить данные
  QString getAuthorizationUrl(const QString &);

private:
  QString oAuthVK_getToken();
  QString token_;
};

#endif // OAUTHPROVIDER_H
