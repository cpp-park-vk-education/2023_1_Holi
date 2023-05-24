#ifndef OAUTHPROVIDER_H
#define OAUTHPROVIDER_H

#include <QtNetworkAuth/QOAuth2AuthorizationCodeFlow>
#include <QtNetworkAuth/QOAuthHttpServerReplyHandler>


#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>




class GoogleSSO : public QObject {
    Q_OBJECT
public:
    GoogleSSO(QObject *parent=nullptr);
    virtual ~GoogleSSO();

public slots:
    void authenticate();

signals:
    void gotToken(const QString& token);

private:
    QOAuth2AuthorizationCodeFlow * google;
};

#endif // OAUTHPROVIDER_H
