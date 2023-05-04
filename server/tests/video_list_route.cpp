//
// Created by Алексей on 03.05.2023.
//

//
// Created by Алексей on 01.05.2023.
//

#include <gtest/gtest.h>
#include <iostream>

#include "constants.h"
#include "i_db_model.h"
#include "message_info.h"
#include "video_list_route.h"


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
                    "videos": ["13", "24", "11"]
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


TEST(VideoListRouteTest, GetNegativeId) {
    EXPECT_EQ(VideoListRoute(user_id, std::make_unique<StabVideoListRouteDbModel>()).Get(negative_id),
              MessageInfo(json::value{}, http::status::not_found));
}

TEST(VideoListRouteTest, GetCommon) {
    MessageInfo expected_response(json::parse(R"(
        {
            "name": "name",
            "image": "image",
            "exported_from": "exported_from",
            "user": "6",
            "videos": ["13", "24", "11"]
        }
    )"), http::status::ok);

    EXPECT_EQ(VideoListRoute(user_id, std::make_unique<StabVideoListRouteDbModel>()).Get(common_id), expected_response);
}

TEST(VideoListRouteTest, PostEmptyJson) {
    EXPECT_EQ(VideoListRoute(user_id, std::make_unique<StabVideoListRouteDbModel>()).Post({}),
              MessageInfo(json::value{}, http::status::bad_request));
}

TEST(VideoListRouteTest, PostIncorrectValueType) {
    auto post_body = json::parse(R"(
        {
            "name": "name",
            "image": "image",
            "exported_from": "exported_from",
            "user": "sueer",
            "videos": ["13", "24", "11"]
        }
    )");

    EXPECT_EQ(VideoListRoute(user_id, std::make_unique<StabVideoListRouteDbModel>()).Post(post_body),
              MessageInfo(json::value{}, http::status::bad_request));
}

TEST(VideoListRouteTest, PostCommon) {
    json::value post_body = json::parse(R"(
        {
            "name": "name",
            "image": "image",
            "exported_from": "exported_from",
            "user": "6",
            "videos": ["13", "24", "11"]
        }
    )");
    MessageInfo expected_response(post_body, http::status::ok);

    EXPECT_EQ(VideoListRoute(user_id, std::make_unique<StabVideoListRouteDbModel>(true)).Post(post_body), expected_response);
}

TEST(VideoListRouteTest, DeleteNegativeId) {
    EXPECT_EQ(VideoListRoute(user_id, std::make_unique<StabVideoListRouteDbModel>()).Delete(negative_id),
              MessageInfo(json::value{}, http::status::not_found));
}

TEST(VideoListRouteTest, DeleteCommon) {
    EXPECT_EQ(VideoListRoute(user_id, std::make_unique<StabVideoListRouteDbModel>(true)).Delete(common_id),
              MessageInfo(json::value{}, http::status::no_content));
}
