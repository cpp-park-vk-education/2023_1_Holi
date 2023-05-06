//
// Created by Алексей on 04.05.2023.
//

#include <gtest/gtest.h>
#include <string>

#include "constants.h"
#include "errors.h"
#include "user.h"


class StabDbConnector : public IDbConnector {
public:
    std::vector<std::map<std::string, std::string>>
    Connect(QString sql_string, QString table_name) override { return {}; }
};

class StabSuccessDbConnector : public IDbConnector {
public:
    std::vector<std::map<std::string, std::string>> Connect(QString sql_string, QString table_name) override {
        return {
                {
                        {"id", std::to_string(common_id)},
                        {"name", "name"},
                        {"surname", "surname"},
                        {"email", "email"},
                        {"avatar", "avatar"},
                        {"login", "login"},
                        {"password", "password"}
                }
        };
    }

};

class StabSelectWithCommonDbConnector : public IDbConnector {
public:
    std::vector<std::map<std::string, std::string>> Connect(QString sql_string, QString table_name) override {
        return {
                {
                        {"id", "1"},
                        {"name", "name"},
                        {"surname", "surname"},
                        {"email", "email"},
                        {"avatar", "avatar"},
                        {"login", "login"},
                        {"password", "password"}
                },
                {
                        {"id", "2"},
                        {"name", "name2"},
                        {"surname", "surname2"},
                        {"email", "email2"},
                        {"avatar", "avatar2"},
                        {"login", "login2"},
                        {"password", "password2"}
                }
        };
    }

};

class StabConditionErrorDbConnector : public IDbConnector {
public:
    std::vector<std::map<std::string, std::string>>
    Connect(QString sql_string, QString table_name) override {
        throw(ConditionError("incorrect condition"));
    }
};

TEST(UserModelTest, GetNegativeId) {
    User model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Get(negative_id), json::value{});
}

TEST(UserModelTest, GetCommon) {
    User model(user_id, std::make_unique<StabSuccessDbConnector>());
    EXPECT_EQ(model.Get(common_id), json::parse(R"(
                {
                    "name": "name",
                    "surname": "surname",
                    "email": "email",
                    "avatar": "avatar",
                    "login": "login",
                    "password": "password"
                }
            )"));
}

TEST(UserModelTest, DeleteNegativeId) {
    User model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Delete(negative_id), false);
}

TEST(UserModelTest, DeleteCommon) {
    User model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Delete(common_id), true);
}

TEST(UserModelTest, SelectWithIncorrectCondition) {
    User model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.SelectWith("4567t8y9uoipk["), json::value{});
}

TEST(UserModelTest, SelectWithEmptyCondition) {
    User model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.SelectWith(""), json::value{});
}

TEST(UserModelTest, SelectWithCommon) {
    User model(user_id, std::make_unique<StabSelectWithCommonDbConnector>());
    auto expected = json::parse(R"(
        [
                {
                        "id": "1",
                        "name": "name",
                        "surname": "surname",
                        "email": "email",
                        "avatar": "avatar",
                        "login": "login",
                        "password": "password"
                },
                {
                        "id": "2",
                        "name": "name2",
                        "surname": "surname2",
                        "email": "email2",
                        "avatar": "avatar2",
                        "login": "login2",
                        "password": "password2"
                }
        ]
    )");
    EXPECT_EQ(model.SelectWith("id BETWEEN 1 AND 2"), expected);
}

TEST(UserModelTest, DeleteWithIncorrectCondition) {
    User model(user_id, std::make_unique<StabConditionErrorDbConnector>());
    ASSERT_NO_THROW(model.DeleteWith("f097867ftyugi90-908uiy"));
    EXPECT_EQ(model.DeleteWith("f097867ftyugi90-908uiy"), false);
}

TEST(UserModelTest, DeleteWithEmptyCondition) {
    User model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.DeleteWith(""), false);
}

TEST(UserModelTest, DeleteWithCommon) {
    User model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.DeleteWith("id BETWEEN 1 AND 2"), true);
}

TEST(UserModelTest, SaveEmptyParams) {
    User model;
    EXPECT_EQ(model.Save(), false);
}

TEST(UserModelTest, SaveCommonParams) {
    User model(
            "name",
            "surname",
            "email",
            "avatar",
            "login",
            "password",
            {1, 2, 3},
            {3, 2, 1}
    );
    model.SetConnector(std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Save(), true);
}

TEST(UserModelTest, AlterNegativeId) {
    User model(
            "name",
            "surname",
            "email",
            "avatar",
            "login",
            "password",
            {1, 2, 3},
            {3, 2, 1}
    );
    model.SetConnector(std::make_unique<StabDbConnector>());

    EXPECT_EQ(model.Alter(negative_id), false);
}

TEST(UserModelTest, AlterCommon) {
    User model(
            "name",
            "surname",
            "email",
            "avatar",
            "login",
            "password",
            {1, 2, 3},
            {3, 2, 1}
    );
    model.SetConnector(std::make_unique<StabDbConnector>());

    EXPECT_EQ(model.Alter(common_id), true);
}