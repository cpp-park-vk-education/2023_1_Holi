//
// Created by Алексей on 04.05.2023.
//


#include <gtest/gtest.h>
#include <string>

#include "../constants.h"
#include "orm/errors.h"
#include "orm/chat.h"


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
                        {"image", "image"},
                        {"created_at", "20.05.2023 12:34:56"},
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
                        {"image", "image"},
                        {"created_at", "20.05.2023 12:34:56"},
                },
                {
                        {"id", "2"},
                        {"name", "name2"},
                        {"image", "image2"},
                        {"created_at", "20.05.2023 12:34:56"},
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

TEST(ChatModelTest, GetNegativeId) {
    Chat model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Get(negative_id), json::value{});
}

TEST(ChatModelTest, GetCommon) {
    Chat model(user_id, std::make_unique<StabSuccessDbConnector>());
    EXPECT_EQ(model.Get(common_id), json::parse(R"(
                {
                    "name": "name",
                    "image": "image",
                    "created_at": "20.05.2023 12:34:56"
                }
            )"));
}

TEST(ChatModelTest, DeleteNegativeId) {
    Chat model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Delete(negative_id), false);
}

TEST(ChatModelTest, DeleteCommon) {
    Chat model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Delete(common_id), true);
}

TEST(ChatModelTest, SelectWithIncorrectCondition) {
    Chat model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.SelectWith("4567t8y9uoipk["), json::value{});
}

TEST(ChatModelTest, SelectWithEmptyCondition) {
    Chat model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.SelectWith(""), json::value{});
}

TEST(ChatModelTest, SelectWithCommon) {
    Chat model(user_id, std::make_unique<StabSelectWithCommonDbConnector>());
    auto expected = json::parse(R"(
         [
            {
                "id": "1",
                "name": "name",
                "image": "image",
                "created_at": "20.05.2023 12:34:56"
            },
            {
                "id": "2",
                "name": "name2",
                "image": "image2",
                "created_at": "20.05.2023 12:34:56"
            }
        ]
    )");
    EXPECT_EQ(model.SelectWith("id BETWEEN 1 AND 2"), expected);
}

TEST(ChatModelTest, DeleteWithIncorrectCondition) {
    Chat model(user_id, std::make_unique<StabConditionErrorDbConnector>());
    ASSERT_NO_THROW(model.DeleteWith("f097867ftyugi90-908uiy"));
    EXPECT_EQ(model.DeleteWith("f097867ftyugi90-908uiy"), false);
}

TEST(ChatModelTest, DeleteWithEmptyCondition) {
    Chat model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.DeleteWith(""), false);
}

TEST(ChatModelTest, DeleteWithCommon) {
    Chat model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.DeleteWith("id BETWEEN 1 AND 2"), true);
}

TEST(ChatModelTest, SaveEmptyParams) {
    Chat model;
    EXPECT_EQ(model.Save(), false);
}

TEST(ChatModelTest, SaveCommonParams) {
    Chat model(
            "name",
            "image",
            QDateTime::fromString("20.05.2023 12:34:56"),
            {13, 43, 4},
            {5, 24, 54}
    );
    model.SetConnector(std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Save(), true);
}

TEST(ChatModelTest, AlterNegativeId) {
    Chat model(
            "name",
            "image",
            QDateTime::fromString("20.05.2023 12:34:56"),
            {13, 43, 4},
            {5, 24, 54}
    );
    model.SetConnector(std::make_unique<StabDbConnector>());

    EXPECT_EQ(model.Alter(negative_id), false);
}

TEST(ChatModelTest, AlterCommon) {
    Chat model(
            "name",
            "image",
            QDateTime::fromString("20.05.2023 12:34:56"),
            {13, 43, 4},
            {5, 24, 54}
    );
    model.SetConnector(std::make_unique<StabDbConnector>());

    EXPECT_EQ(model.Alter(common_id), true);
}