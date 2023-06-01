#ifndef OAUTHPROVIDER_H
#define OAUTHPROVIDER_H

#include <QtNetworkAuth/QOAuth2AuthorizationCodeFlow>
#include <QtNetworkAuth/QOAuthHttpServerReplyHandler>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include "client/message_info.h"
#include <QMessageBox>

//Альбомы Ютуба
struct YTAlbums{
    QString title ;
    QString description;
    QString channelId;
    QString id;
};

struct YTVideo{
    QString title;
    QString id;
    QString description;
};


QVector<YTAlbums> YouTube_Albums(MessageInfo info);
QVector<QString> YouTube_Albums_DB(MessageInfo info);
QVector<YTVideo> YouTube_Video(MessageInfo info);
QVector<QString> YouTube_Videos_DB(MessageInfo info);


struct VKAlbums{
    QString id;
    QString owner_id;
    QString title;
    QString responseType;
};

QVector<VKAlbums> VKontakte_Albums(MessageInfo info);

QVector<QString> VKontakte_Albums_DB(MessageInfo info);

#endif // OAUTHPROVIDER_H
