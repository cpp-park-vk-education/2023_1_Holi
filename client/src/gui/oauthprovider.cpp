#include "oauthprovider.h"


GoogleAuth::GoogleAuth(QObject *parent) : QObject(parent)
{
    this->google = new QOAuth2AuthorizationCodeFlow(this);
    this->google->setScope("email");
    connect(this->google, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,[=](QUrl url){
        QUrlQuery query(url);
        query.addQueryItem("prompt", "consent");      // Param required to get data everytime
        query.addQueryItem("access_type", "offline"); // Needed for Refresh Token (as AccessToken expires shortly)
        url.setQuery(query);
        QDesktopServices::openUrl(url);
    });

    this->google->setAuthorizationUrl(QUrl("https://accounts.google.com/o/oauth2/auth"));
    this->google->setAccessTokenUrl(QUrl("https://oauth2.googleapis.com/token"));
    this->google->setClientIdentifier("869025620327-u6eu9r31nr3p7qdaiqvkgd9g53vtah6q.apps.googleusercontent.com");
    this->google->setClientIdentifierSharedKey("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");

    auto replyHandler = new QOAuthHttpServerReplyHandler(8080, this);

    connect(this->google, &QOAuth2AuthorizationCodeFlow::granted, [=]() {
            qDebug() << __FUNCTION__ << __LINE__ << "Access Granted!";

            auto reply = this->google->get(QUrl("https://www.googleapis.com/drive/v3/files"));
            connect(reply, &QNetworkReply::finished, [reply]() {
                qDebug() << "REQUEST FINISHED. Error? " << (reply->error() != QNetworkReply::NoError);
                qDebug() << reply->readAll();
            });
        });
}

void GoogleAuth::click()
{
    this->google->grant();
}
