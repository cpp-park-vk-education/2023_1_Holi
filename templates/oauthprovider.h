
#ifndef OAUTHPROVIDER_H
#define OAUTHPROVIDER_H


#include <QObject>
#include <QUrl>

class OAuthProvider : public QObject
{
    Q_OBJECT
public:
    explicit OAuthProvider(QObject* parent = nullptr);
    QString getAccessToken(const QString&);//получить токен доступа
    QVector<QString> getUserProfile(int id, const QString&);//получить данные пользователя
    QString getAuthorizationUrl(const QString&);//получить адрес авторизацияя
signals:



private:


};

#endif // OAUTHPROVIDER_H
