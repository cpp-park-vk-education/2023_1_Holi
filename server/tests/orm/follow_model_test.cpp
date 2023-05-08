//
// Created by Алексей on 04.05.2023.
//

#include <gtest/gtest.h>
#include <string>

#include "../constants.h"
#include "orm/errors.h"
#include "orm/follow.h"


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
                        {"sent_at", "20.05.2023 12:34:56"},
                        {"first_user_id", "2"},
                        {"second_user_id", "3"},
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
                        {"sent_at", "20.05.2020 12:34:56"},
                        {"first_user_id", "2"},
                        {"second_user_id", "3"},
                },
                {
                        {"id", "2"},
                        {"sent_at", "20.05.2023 12:34:56"},
                        {"first_user_id", "11"},
                        {"second_user_id", "5"},
                }
        };
    }

};

class StabConditionErrorDbConnector : public IDbConnector {
public:
    std::vector<std::map<std::string, std::string>>
    Connect(QString sql_string, QString table_name) override {
        throw (ConditionError("incorrect condition"));
    }
};

TEST(FollowModelTest, GetNegativeId) {
    Follow model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Get(negative_id), json::value{});
}

TEST(FollowModelTest, GetCommon) {
    Follow model(user_id, std::make_unique<StabSuccessDbConnector>());
    EXPECT_EQ(model.Get(common_id), json::parse(R"(
                {
                    "sent_at": "20.05.2023 12:34:56",
                    "first_user_id": "2",
                    "second_user_id": "3"
                }
            )"));
}

TEST(FollowModelTest, DeleteNegativeId) {
    Follow model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Delete(negative_id), false);
}

TEST(FollowModelTest, DeleteCommon) {
    Follow model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Delete(common_id), true);
}

TEST(FollowModelTest, SelectWithIncorrectCondition) {
    Follow model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.SelectWith("4567t8y9uoipk["), json::value{});
}

TEST(FollowModelTest, SelectWithEmptyCondition) {
    Follow model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.SelectWith(""), json::value{});
}

TEST(FollowModelTest, SelectWithCommon) {
    Follow model(user_id, std::make_unique<StabSelectWithCommonDbConnector>());
    auto expected = json::parse(R"(
        [
            {
              "id": "1",
              "sent_at": "20.05.2020 12:34:56",
              "first_user_id": "2",
              "second_user_id": "3"
            },
            {
              "id": "2",
              "sent_at": "20.05.2023 12:34:56",
              "first_user_id": "11",
              "second_user_id": "5"
            }
        ]
    )");
    EXPECT_EQ(model.SelectWith("id BETWEEN 1 AND 2"), expected);
}

TEST(FollowModelTest, DeleteWithIncorrectCondition) {
    Follow model(user_id, std::make_unique<StabConditionErrorDbConnector>());
    ASSERT_NO_THROW(model.DeleteWith("f097867ftyugi90-908uiy"));
    EXPECT_EQ(model.DeleteWith("f097867ftyugi90-908uiy"), false);
}

TEST(FollowModelTest, DeleteWithEmptyCondition) {
    Follow model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.DeleteWith(""), false);
}

TEST(FollowModelTest, DeleteWithCommon) {
    Follow model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.DeleteWith("id BETWEEN 1 AND 2"), true);
}

TEST(FollowModelTest, SaveEmptyParams) {
    Follow model;
    EXPECT_EQ(model.Save(), false);
}

TEST(FollowModelTest, SaveCommonParams) {
    Follow model(
            QDateTime::fromString("20.05.2023 12:34:56"),
            2,
            5
    );
    model.SetConnector(std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Save(), true);
}

TEST(FollowModelTest, AlterNegativeId) {
    Follow model(
            QDateTime::fromString("20.05.2023 12:34:56"),
            2,
            5
    );
    model.SetConnector(std::make_unique<StabDbConnector>());

    EXPECT_EQ(model.Alter(negative_id), false);
}

TEST(FollowModelTest, AlterCommon) {
    Follow model(
            QDateTime::fromString("20.05.2023 12:34:56"),
            2,
            5
    );
    model.SetConnector(std::make_unique<StabDbConnector>());

    EXPECT_EQ(model.Alter(common_id), true);
}