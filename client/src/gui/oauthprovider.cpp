#include "requestmaker.h"
#include "oauthprovider.h"
#include <QDebug>
OAuthProvider::OAuthProvider( QObject *parent)
    : QObject{parent}
{

}


QString OAuthProvider::getAccessToken(const QString& serv){

    return "";
}

QVector<QString> OAuthProvider::getUserProfile(int id_,const QString& access_token){
    QVector<QString> result;
    return result;
}


QString OAuthProvider::getAuthorizationUrl(const QString& service){
    return "";
}
