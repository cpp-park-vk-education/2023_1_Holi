#include "gmock/gmock.h"
#include <QApplication>
#include <QCryptographicHash>
#include <QObject>
#include <QUrl>
#include <QUrlQuery>
#include <gtest/gtest.h>

#include "oauthprovider.h"

#include "authenticationmanager.h"

#include "registrationmanager.h"
#include "user.h"

/*// OAuthProvider
class MockOAuthProvider : public OAuthProvider {
public:
  QString getAccessToken() { return "token"; }
  QVector<QString> getUserProfile(int id_, const QString &access_token,
                                  const QString &service) {

    QVector<QString> user;

    QString first_name = "A";
    QString last_name = "B";
    QString id = "12345";

    user.push_back(first_name);
    user.push_back(last_name);
    user.push_back(id);

    return user;
  }

  QString getAuthorizationUrl(const QString &state) {
    QUrl url("https://accounts.google.com/o/oauth2/v2/auth");
    QUrlQuery query;
    query.addQueryItem("client_id", "YOUR_CLIENT_ID");
    query.addQueryItem("redirect_uri", "YOUR_REDIRECT_URI");
    query.addQueryItem("response_type", "code");
    query.addQueryItem("scope", "email profile");
    query.addQueryItem("state", state);
    url.setQuery(query);
    return QString(url.toString());
  }
};

// getAccessToken
TEST(OAProvider, getAccessToken1) {
  MockOAuthProvider mOAP;

  EXPECT_EQ(mOAP.getAccessToken(), "token");
}

// getUserProfile
TEST(OAProvider, getUserProfile1) {
  MockOAuthProvider mOAP;

  QVector<QString> user_;
  QString first_name = "A";
  QString last_name = "B";
  QString id = "12345";

  user_.push_back(first_name);
  user_.push_back(last_name);
  user_.push_back(id);
  EXPECT_EQ(mOAP.getUserProfile(1, "YOU_ACCESS_TOKEN", "VK"), user_);
}

// getAuthorizationUrl
TEST(OAProvider, getAuthorizationUrl) {
  MockOAuthProvider mOAP;

  QUrl url("https://accounts.google.com/o/oauth2/v2/auth");

  QUrlQuery query;

  query.addQueryItem("client_id", "YOUR_CLIENT_ID");
  query.addQueryItem("redirect_uri", "YOUR_REDIRECT_URI");
  query.addQueryItem("response_type", "code");
  query.addQueryItem("scope", "email profile");
  query.addQueryItem("state", "state");

  url.setQuery(query);

  EXPECT_EQ(mOAP.getAuthorizationUrl("state"), QString(url.toString()));
}

class StubAuthManager : public AuthenticationManager {
public:
  bool authenticateUser(const QString &login, const QString &password) {
    QString hash_log = makeHash("login");
    QString hash_pas = makeHash("password");

    if (hash_log == makeHash(login) && hash_pas == makeHash(password)) {
      return true;
    }
    return false;
  }

  bool authorizeUser(bool state) {
    if (state == true) {
      return true;
    }
    return false;
  }

  bool logoutUser(const QString &userID) { return true; }

  QString makeHash(const QString &str) {
    QByteArray data = str.toUtf8();
    QByteArray hash =
        QCryptographicHash::hash(data, QCryptographicHash::Sha256);
    return QString(hash.toHex());
  }
};

// AuthenticationManager
TEST(AuthenticationManager, authenticateUser) {
  StubAuthManager sAM;
  EXPECT_EQ(sAM.authenticateUser("login", "password"), true);
}

TEST(AuthenticationManager, authenticateUser_f) {
  StubAuthManager sAM;
  EXPECT_EQ(sAM.authenticateUser("login", ""), false);
}

// authorizeUser
TEST(AuthenticationManager, authorizeUser) {
  StubAuthManager sAM;
  EXPECT_EQ(sAM.authorizeUser(sAM.authenticateUser("login", "password")), true);
}

TEST(AuthenticationManager, authorizeUser_f) {
  StubAuthManager sAM;
  EXPECT_EQ(sAM.authorizeUser(sAM.authenticateUser("", "password")), false);
}

// makeHash
TEST(makeHash, makeHashEQ) {
  StubAuthManager sAM;
  QString testHash1 = sAM.makeHash("Hello World!");
  EXPECT_EQ(testHash1, sAM.makeHash("Hello World!"));
}

// makeHash
TEST(makeHash, makeHashEQ_f) {
  StubAuthManager sAM;
  QString testHash1 = sAM.makeHash("Hello World!");
  EXPECT_EQ(testHash1, sAM.makeHash("Hello World"));
}

class stubRegistrationManager : RegistrationManager {
public:
  User registerUser(const QString &login, const QString &email,
                    const QString &password) {

    User user(login, email, password);
    return user;
  }

  bool validateUserDetails(const User &user) {
    // Проверяем, что все три поля не пустые
    if (user.getLogin().isEmpty() || user.getEmail().isEmpty() ||
        user.getPassword().isEmpty()) {
      return false;
    }

    // Проверяем, что электронная почта содержит символ @
    if (!user.getEmail().contains('@')) {
      return false;
    }

    // Проверяем, что пароль длиннее 8 символов
    if (user.getPassword().length() < 8) {
      return false;
    }

    // Если все проверки прошли успешно, то возвращаем true
    return true;
  }

  bool saveUserToDatabase(User &user) {
    if (validateUserDetails(user)) {
      StubAuthManager sAM;
      user.setLogin(sAM.makeHash(user.getLogin()));
      user.setEmail(sAM.makeHash(user.getEmail()));
      user.setPassword(sAM.makeHash(user.getPassword()));
      //сохраняем
      return true;
    }
    return false;
  }
};

TEST(RegistrationManager, registerUser) {
  QString login = ("login");
  QString email = ("email");
  QString password = ("password");

  User user(login, email, password);

  stubRegistrationManager sRG;

  EXPECT_EQ(sRG.registerUser("login", "email", "password"), user);
}

// validateUserDetails
TEST(RegistrationManager, validateUserDetails) {
  stubRegistrationManager sRG;
  bool state = sRG.validateUserDetails(
      sRG.registerUser("login", "@email@@", "password12345"));
  EXPECT_EQ(state, true);
}

// validateUserDetails
TEST(RegistrationManager, validateUserDetails_f) {
  stubRegistrationManager sRG;
  bool state =
      sRG.validateUserDetails(sRG.registerUser("login", "email", "password"));
  EXPECT_EQ(state, false);
}

// saveUserToDatabase
TEST(RegistrationManager, saveUserToDatabase) {
  User user("11", "@", "12345678");

  stubRegistrationManager sRG;
  EXPECT_EQ(sRG.saveUserToDatabase(user), true);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/
