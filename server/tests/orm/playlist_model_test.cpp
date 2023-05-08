//
// Created by Алексей on 04.05.2023.
//


#include <gtest/gtest.h>
#include <string>

#include "../constants.h"
#include "orm/errors.h"
#include "orm/playlist.h"


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
                        {"exported_from", "exported_from"},
                        {"user", std::to_string(user_id)},
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
                        {"exported_from", "exported_from"},
                        {"user", "3"},
                },
                {
                        {"id", "2"},
                        {"name", "name2"},
                        {"image", "image2"},
                        {"exported_from", "exported_from2"},
                        {"user", "45"},
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

TEST(PlaylistModelTest, GetNegativeId) {
    Playlist model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Get(negative_id), json::value{});
}

TEST(PlaylistModelTest, GetCommon) {
    Playlist model(user_id, std::make_unique<StabSuccessDbConnector>());
    EXPECT_EQ(model.Get(common_id), json::parse(R"(
                {
                    "name": "name",
                    "image": "image",
                    "exported_from": "exported_from",
                    "user": "2"
                }
            )"));
}

TEST(PlaylistModelTest, DeleteNegativeId) {
    Playlist model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Delete(negative_id), false);
}

TEST(PlaylistModelTest, DeleteCommon) {
    Playlist model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Delete(common_id), true);
}

TEST(PlaylistModelTest, SelectWithIncorrectCondition) {
    Playlist model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.SelectWith("4567t8y9uoipk["), json::value{});
}

TEST(PlaylistModelTest, SelectWithEmptyCondition) {
    Playlist model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.SelectWith(""), json::value{});
}

TEST(PlaylistModelTest, SelectWithCommon) {
    Playlist model(user_id, std::make_unique<StabSelectWithCommonDbConnector>());
    auto expected = json::parse(R"(
        [
            {
                "id": "1",
                "name": "name",
                "image": "image",
                "exported_from": "exported_from",
                "user": "3"
            },
            {
                "id": "2",
                "name": "name2",
                "image": "image2",
                "exported_from": "exported_from2",
                "user": "45"
            }
        ]
    )");
    EXPECT_EQ(model.SelectWith("id BETWEEN 1 AND 2"), expected);
}

TEST(PlaylistModelTest, DeleteWithIncorrectCondition) {
    Playlist model(user_id, std::make_unique<StabConditionErrorDbConnector>());
    ASSERT_NO_THROW(model.DeleteWith("f097867ftyugi90-908uiy"));
    EXPECT_EQ(model.DeleteWith("f097867ftyugi90-908uiy"), false);
}

TEST(PlaylistModelTest, DeleteWithEmptyCondition) {
    Playlist model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.DeleteWith(""), false);
}

TEST(PlaylistModelTest, DeleteWithCommon) {
    Playlist model(user_id, std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.DeleteWith("id BETWEEN 1 AND 2"), true);
}

TEST(PlaylistModelTest, SaveEmptyParams) {
    Playlist model;
    EXPECT_EQ(model.Save(), false);
}

TEST(PlaylistModelTest, SaveCommonParams) {
    Playlist model(
            "name",
            "image",
            "exported_from",
            2,
            {5, 24, 54}
    );
    model.SetConnector(std::make_unique<StabDbConnector>());
    EXPECT_EQ(model.Save(), true);
}

TEST(PlaylistModelTest, AlterNegativeId) {
    Playlist model(
            "name",
            "image",
            "exported_from",
            2,
            {5, 24, 54}
    );
    model.SetConnector(std::make_unique<StabDbConnector>());

    EXPECT_EQ(model.Alter(negative_id), false);
}

TEST(PlaylistModelTest, AlterCommon) {
    Playlist model(
            "name",
            "image",
            "exported_from",
            2,
            {5, 24, 54}
    );
    model.SetConnector(std::make_unique<StabDbConnector>());

    EXPECT_EQ(model.Alter(common_id), true);
}