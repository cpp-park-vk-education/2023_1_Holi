//
// Created by Алексей on 04.05.2023.
//

#include <gtest/gtest.h>
#include <string>

#include "../constants.h"
#include "orm/errors.h"
#include "orm/profile_reference.h"


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
                        {"reference", "reference"},
                        {"service", "service"},
                        {"user_id", "2"},
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
                        {"reference", "reference"},
                        {"service", "service"},
                        {"user_id", "2"},
                },
                {
                        {"id", "2"},
                        {"reference", "reference2"},
                        {"service", "service2"},
                        {"user_id", "34"},
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

TEST(ProfileReferenceModelTest, GetNegativeId) {
    ProfileReference model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Get(negative_id), json::value{});
}

TEST(ProfileReferenceModelTest, GetCommon) {
    ProfileReference model(user_id, std::make_unique<StabSuccessDbConnector>());
    EXPECT_EQ(model.Get(common_id), json::parse(R"(
                {
                    "reference": "reference",
                    "service": "service",
                    "user_id": "2"
                }
            )"));
}

TEST(ProfileReferenceModelTest, DeleteNegativeId) {
    ProfileReference model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Delete(negative_id), false);
}

TEST(ProfileReferenceModelTest, DeleteCommon) {
    ProfileReference model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Delete(common_id), true);
}

TEST(ProfileReferenceModelTest, SelectWithIncorrectCondition) {
    ProfileReference model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.SelectWith("4567t8y9uoipk["), json::value{});
}

TEST(ProfileReferenceModelTest, SelectWithEmptyCondition) {
    ProfileReference model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.SelectWith(""), json::value{});
}

TEST(ProfileReferenceModelTest, SelectWithCommon) {
    ProfileReference model(user_id, std::make_unique<StabSelectWithCommonDbConnector>());
    auto expected = json::parse(R"(
        [
            {
                "id": "1",
                "reference": "reference",
                "service": "service",
                "user_id": "2"
            },
            {
                "id": "2",
                "reference": "reference2",
                "service": "service2",
                "user_id": "34"
            }
        ]
    )");
    EXPECT_EQ(model.SelectWith("id BETWEEN 1 AND 2"), expected);
}

TEST(ProfileReferenceModelTest, DeleteWithIncorrectCondition) {
    ProfileReference model(user_id, std::make_unique<StabConditionErrorDbConnector>());
    ASSERT_NO_THROW(model.DeleteWith("f097867ftyugi90-908uiy"));
    EXPECT_EQ(model.DeleteWith("f097867ftyugi90-908uiy"), false);
}

TEST(ProfileReferenceModelTest, DeleteWithEmptyCondition) {
    ProfileReference model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.DeleteWith(""), false);
}

TEST(ProfileReferenceModelTest, DeleteWithCommon) {
    ProfileReference model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.DeleteWith("id BETWEEN 1 AND 2"), true);
}

TEST(ProfileReferenceModelTest, SaveEmptyParams) {
    ProfileReference model;
    EXPECT_EQ(model.Save(), false);
}

TEST(ProfileReferenceModelTest, SaveCommonParams) {
    ProfileReference model(
            "reference",
            "service",
            2
    );
    model.SetConnector(std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Save(), true);
}

TEST(ProfileReferenceModelTest, AlterNegativeId) {
    ProfileReference model(
            "reference",
            "service",
            2
    );
    model.SetConnector(std::make_unique<StabDbConnector>());

    EXPECT_EQ(model.Alter(negative_id), false);
}

TEST(ProfileReferenceModelTest, AlterCommon) {
    ProfileReference model(
            "reference",
            "service",
            2
    );
    model.SetConnector(std::make_unique<StabDbConnector>());

    EXPECT_EQ(model.Alter(common_id), true);
}