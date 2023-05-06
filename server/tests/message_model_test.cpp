//
// Created by Алексей on 04.05.2023.
//

#include <gtest/gtest.h>
#include <string>

#include "constants.h"
#include "errors.h"
#include "message.h"


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
                        {"text", "text"},
                        {"sent_at", "20.05.2023 12:34:56"},
                        {"user_id", "2"},
                        {"chat_id", "3"},
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
                        {"text", "text"},
                        {"sent_at", "20.05.2023 12:34:56"},
                        {"user_id", "2"},
                        {"chat_id", "3"},
                },
                {
                        {"id", "2"},
                        {"text", "text2"},
                        {"sent_at", "20.05.2022 12:34:56"},
                        {"user_id", "21"},
                        {"chat_id", "5"},
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

TEST(MessageModelTest, GetNegativeId) {
    Message model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Get(negative_id), json::value{});
}

TEST(MessageModelTest, GetCommon) {
    Message model(user_id, std::make_unique<StabSuccessDbConnector>());
    EXPECT_EQ(model.Get(common_id), json::parse(R"(
                {
                    "text": "text",
                    "sent_at": "20.05.2023 12:34:56",
                    "user_id": "2",
                    "chat_id": "5"
                }
            )"));
}

TEST(MessageModelTest, DeleteNegativeId) {
    Message model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Delete(negative_id), false);
}

TEST(MessageModelTest, DeleteCommon) {
    Message model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Delete(common_id), true);
}

TEST(MessageModelTest, SelectWithIncorrectCondition) {
    Message model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.SelectWith("4567t8y9uoipk["), json::value{});
}

TEST(MessageModelTest, SelectWithEmptyCondition) {
    Message model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.SelectWith(""), json::value{});
}

TEST(MessageModelTest, SelectWithCommon) {
    Message model(user_id, std::make_unique<StabSelectWithCommonDbConnector>());
    auto expected = json::parse(R"(
        [
                {
                        "id": "1",
                        "text": "text",
                        "sent_at": "20.05.2023 12:34:56",
                        "user_id": "2",
                        "chat_id": "3"
                },
                {
                        "id": "2",
                        "text": "text2",
                        "sent_at": "20.05.2022 12:34:56",
                        "user_id": "21",
                        "chat_id": "5"
                }
        ]
    )");
    EXPECT_EQ(model.SelectWith("id BETWEEN 1 AND 2"), expected);
}

TEST(MessageModelTest, DeleteWithIncorrectCondition) {
    Message model(user_id, std::make_unique<StabConditionErrorDbConnector>());
    ASSERT_NO_THROW(model.DeleteWith("f097867ftyugi90-908uiy"));
    EXPECT_EQ(model.DeleteWith("f097867ftyugi90-908uiy"), false);
}

TEST(MessageModelTest, DeleteWithEmptyCondition) {
    Message model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.DeleteWith(""), false);
}

TEST(MessageModelTest, DeleteWithCommon) {
    Message model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.DeleteWith("id BETWEEN 1 AND 2"), true);
}

TEST(MessageModelTest, SaveEmptyParams) {
    Message model;
    EXPECT_EQ(model.Save(), false);
}

TEST(MessageModelTest, SaveCommonParams) {
    Message model(
            "text",
            QDateTime::fromString("20.05.2023 12:34:56"),
            2,
            5
    );
    model.SetConnector(std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Save(), true);
}

TEST(MessageModelTest, AlterNegativeId) {
    Message model(
            "text",
            QDateTime::fromString("20.05.2023 12:34:56"),
            2,
            5
    );
    model.SetConnector(std::make_unique<StabDbConnector>());

    EXPECT_EQ(model.Alter(negative_id), false);
}

TEST(MessageModelTest, AlterCommon) {
    Message model(
            "text",
            QDateTime::fromString("20.05.2023 12:34:56"),
            2,
            5
    );
    model.SetConnector(std::make_unique<StabDbConnector>());

    EXPECT_EQ(model.Alter(common_id), true);
}