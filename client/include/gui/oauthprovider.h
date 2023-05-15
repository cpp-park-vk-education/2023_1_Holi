#ifndef OAUTHPROVIDER_H
#define OAUTHPROVIDER_H

#include <QDebug>
#include <QDesktopServices>
#include <QFile>
#include <QJsonDocument>
#include <QtNetworkAuth/QOAuth2AuthorizationCodeFlow>
#include <QtNetworkAuth/QOAuthHttpServerReplyHandler>
#include <QObject>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QUrlQuery>

#include <QDesktopServices>


class GoogleAuth : public QObject {
  Q_OBJECT
public:
  explicit GoogleAuth(QObject *parent = nullptr);
  Q_INVOKABLE void click();


private:
  QOAuth2AuthorizationCodeFlow * google;

};

#endif // OAUTHPROVIDER_H
