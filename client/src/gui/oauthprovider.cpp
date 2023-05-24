#include "oauthprovider.h"
#include <QtNetworkAuth/QAbstractOAuth>
#include <QtNetworkAuth/QAbstractOAuth2>

#include <QString>
#include <QDir>
#include <QUrl>
#include <QOAuthHttpServerReplyHandler>
#include <QDesktopServices>

#define CLIENT_ID "YOUR-CLIENT-ID"
#define CLIENT_SECRET "YOUR-CLIENT-SECRET"
#define AUTH_URI "https://accounts.google.com/o/oauth2/auth"
#define TOKEN_URI "https://oauth2.googleapis.com/token"
#define REDIRECT_URI "http://127.0.0.1:8080/"

GoogleSSO::GoogleSSO(QObject *parent) : QObject(parent) {
    this->google = new QOAuth2AuthorizationCodeFlow(this);
    this->google->setScope("email");
    connect(this->google, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, &QDesktopServices::openUrl);

    const QUrl authUri(AUTH_URI);
    const auto clientId = CLIENT_ID;
    const QUrl tokenUri(TOKEN_URI);
    const auto clientSecret(CLIENT_SECRET);
    const QUrl redirectUri(REDIRECT_URI);
    const auto port = static_cast<quint16>(redirectUri.port());
    this->google->setAuthorizationUrl(authUri);
    this->google->setClientIdentifier(clientId);
    this->google->setAccessTokenUrl(tokenUri);
    this->google->setClientIdentifierSharedKey(clientSecret);

   /* this->google->setModifyParametersFunction([](QAbstractOAuth2::Stage stage, QVariantMap* parameters) {
        // Percent-decode the "code" parameter so Google can match it
        if (stage == QAbstractOAuth::Stage::RequestingAccessToken) {
            QByteArray code = parameters->value("code").toByteArray();
            (*parameters)["code"] = QUrl::fromPercentEncoding(code);
        }
    });
*/
    QOAuthHttpServerReplyHandler* replyHandler = new QOAuthHttpServerReplyHandler(port, this);
    this->google->setReplyHandler(replyHandler);

    connect(this->google, &QOAuth2AuthorizationCodeFlow::granted, [=](){
        const QString token = this->google->token();
        emit gotToken(token);

    });
}

GoogleSSO::~GoogleSSO() {
    delete this->google;
}

// Invoked externally to initiate
void GoogleSSO::authenticate() {
    this->google->grant();
}

/*
oauthprovider.cpp:25:47: error: no viable conversion from '(lambda at /home/nik/pr/2023_1_Holi/client/src/gui/oauthprovider.cpp:25:47)' to 'const QAbstractOAuth::ModifyParametersFunction' (aka 'const function<void (QAbstractOAuth::Stage, QMultiMap<QString, QVariant> *)>')
std_function.h:375:7: note: candidate constructor not viable: no known conversion from '(lambda at /home/nik/pr/2023_1_Holi/client/src/gui/oauthprovider.cpp:25:47)' to 'std::nullptr_t' for 1st argument
std_function.h:386:7: note: candidate constructor not viable: no known conversion from '(lambda at /home/nik/pr/2023_1_Holi/client/src/gui/oauthprovider.cpp:25:47)' to 'const std::function<void (QAbstractOAuth::Stage, QMultiMap<QString, QVariant> *)> &' for 1st argument
std_function.h:404:7: note: candidate constructor not viable: no known conversion from '(lambda at /home/nik/pr/2023_1_Holi/client/src/gui/oauthprovider.cpp:25:47)' to 'std::function<void (QAbstractOAuth::Stage, QMultiMap<QString, QVariant> *)> &&' for 1st argument
std_function.h:435:2: note: candidate template ignored: requirement '_Callable<(lambda at /home/nik/pr/2023_1_Holi/client/src/gui/oauthprovider.cpp:25:47), (lambda at /home/nik/pr/2023_1_Holi/client/src/gui/oauthprovider.cpp:25:47), std::__invoke_result<(lambda at /home/nik/pr/2023_1_Holi/client/src/gui/oauthprovider.cpp:25:47) &, QAbstractOAuth::Stage, QMultiMap<QString, QVariant> *>>::value' was not satisfied [with _Functor = (lambda at /home/nik/pr/2023_1_Holi/client/src/gui/oauthprovider.cpp:25:47)]
oauthprovider.cpp:25:47: note: candidate function
qabstractoauth.h:145:70: note: passing argument to parameter 'modifyParametersFunction' here

oauthprovider.cpp:25:47: ошибка: невозможно преобразование из '(лямбда в /home/nik/pr/2023_1_Holi/client/src/gui/oauthprovider.cpp:25:47)' в 'const QAbstractOAuth::ModifyParametersFunction' (он же 'const function<void (QAbstractOAuth::Stage, QMultiMap<QString, QVariant> *)>')
std_function.h:375:7: примечание: конструктор-кандидат нежизнеспособен: неизвестно преобразование из '(лямбда в /home/nik/pr/2023_1_Holi/client/src/gui/oauthprovider.cpp:25:47)' в 'std ::nullptr_t' для 1-го аргумента
std_function.h:386:7: примечание: конструктор-кандидат нежизнеспособен: неизвестно преобразование из '(лямбда в /home/nik/pr/2023_1_Holi/client/src/gui/oauthprovider.cpp:25:47)' в 'const std::function<void (QAbstractOAuth::Stage, QMultiMap<QString, QVariant> *)> &' для 1-го аргумента
std_function.h:404:7: примечание: конструктор-кандидат нежизнеспособен: неизвестно преобразование из '(лямбда в /home/nik/pr/2023_1_Holi/client/src/gui/oauthprovider.cpp:25:47)' в 'std ::function<void (QAbstractOAuth::Stage, QMultiMap<QString, QVariant> *)> &&' для 1-го аргумента
std_function.h:435:2: примечание: шаблон-кандидат игнорируется: требование '_Callable<(лямбда в /home/nik/pr/2023_1_Holi/client/src/gui/oauthprovider.cpp:25:47), (лямбда в /home /nik/pr/2023_1_Holi/client/src/gui/oauthprovider.cpp:25:47), std::__invoke_result<(лямбда в /home/nik/pr/2023_1_Holi/client/src/gui/oauthprovider.cpp:25 :47) &, QAbstractOAuth::Stage, QMultiMap<QString, QVariant> *>>::value' не был удовлетворен [с _Functor = (лямбда в /home/nik/pr/2023_1_Holi/client/src/gui/oauthprovider. cpp:25:47)]
oauthprovider.cpp:25:47: примечание: функция-кандидат
qabstractoauth.h:145:70: примечание: здесь передается аргумент для параметра «modifyParametersFunction»
*/
