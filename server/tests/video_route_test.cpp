//
// Created by Алексей on 01.05.2023.
//

#include <gtest/gtest.h>
#include <iostream>

#include "constants.h"
#include "i_db_model.h"
#include "message_info.h"
#include "video_route.h"


struct StabVideoListRouteDbModel : public IDbModel {
    bool is_common_;

    explicit StabVideoListRouteDbModel(bool is_common = false) : is_common_(is_common) {}

    json::value Get(int id) override {
        if (id == common_id) {
            return json::parse(R"(
                {
                    "name": "name",
                    "image": "image",
                    "exported_from": "exported_from",
                    "user": "6",
                    "playlists": ["12", "2", "43"]
                }
            )");
        }

        return {};
    }

    bool Delete(int id) override {
        return is_common_;
    }

    bool Save() override { return is_common_; }

    bool Alter(int id) override { return false; }

    json::value SelectAll() override { return {}; };

    json::value SelectWith(QString condition) override { return {}; };

    bool DeleteWith(QString condition) override { return false; };

    void SetConnector(std::unique_ptr<IDbConnector> connector) override {};
};


TEST(VideoRouteTest, GetNegativeId) {
    EXPECT_EQ(VideoRoute(user_id, std::make_unique<StabVideoListRouteDbModel>()).Get(negative_id),
              MessageInfo(json::value{}, http::status::not_found));
}

TEST(VideoRouteTest, GetCommon) {
    MessageInfo expected_response(json::parse(R"(
        {
            "name": "name",
            "image": "image",
            "exported_from": "exported_from",
            "user": "6",
            "playlists": ["12", "2", "43"]
        }
    )"), http::status::ok);

    EXPECT_EQ(VideoRoute(user_id, std::make_unique<StabVideoListRouteDbModel>()).Get(common_id), expected_response);
}

TEST(VideoRouteTest, PostEmptyJson) {
    EXPECT_EQ(VideoRoute(user_id, std::make_unique<StabVideoListRouteDbModel>()).Post({}),
              MessageInfo(json::value{}, http::status::bad_request));
}

TEST(VideoRouteTest, PostIncorrectValueType) {
    auto post_body = json::parse(R"(
        {
            "name": "name",
            "image": "image",
            "exported_from": "exported_from",
            "user": "user",
            "playlists": ["12", "2", "43"]
        }
    )");

    EXPECT_EQ(VideoRoute(user_id, std::make_unique<StabVideoListRouteDbModel>()).Post(post_body),
              MessageInfo(json::value{}, http::status::bad_request));
}

TEST(VideoRouteTest, PostCommon) {
    json::value post_body = json::parse(R"(
        {
            "name": "name",
            "image": "image",
            "exported_from": "exported_from",
            "user": "6",
            "playlists": ["12", "2", "43"]
        }
    )");
    MessageInfo expected_response(post_body, http::status::ok);

    EXPECT_EQ(VideoRoute(user_id, std::make_unique<StabVideoListRouteDbModel>(true)).Post(post_body), expected_response);
}

TEST(VideoRouteTest, DeleteNegativeId) {
    EXPECT_EQ(VideoRoute(user_id, std::make_unique<StabVideoListRouteDbModel>()).Delete(negative_id),
              MessageInfo(json::value{}, http::status::not_found));
}

TEST(VideoRouteTest, DeleteCommon) {
    EXPECT_EQ(VideoRoute(user_id, std::make_unique<StabVideoListRouteDbModel>(true)).Delete(common_id),
              MessageInfo(json::value{}, http::status::no_content));
}
