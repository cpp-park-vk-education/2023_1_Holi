//
// Created by Алексей on 03.05.2023.
//

#include <gtest/gtest.h>

#include "request_handling/router.h"
#include "request_handling/parsed_request.h"


TEST(RouterTest, RouteWithNoParams) {
    Router router;

    ParsedRequest request(
            {},
            "/video",
            http::verb::get
    );

    EXPECT_EQ(router.Route(request), MessageInfo({}, http::status::bad_request));
}

TEST(RouterTest, RouteWithInvalidParams) {
    Router router;

    ParsedRequest request(
            url::params_encoded_view("user_id=Artemij&resource_id=23"),
            "/video",
            http::verb::get
    );

    EXPECT_EQ(router.Route(request), MessageInfo({}, http::status::bad_request));
}

TEST(RouterTest, RouteWithNoPath) {
    Router router;

    ParsedRequest request(
            url::params_encoded_view("user_id=63"),
            "",
            http::verb::post,
            json::parse(R"(
                        {
                            "id": "5",
                            "name": "name",
                            "surname": "surname",
                            "email": "email",
                            "login": "login",
                            "password": "password"
                        }
                    )")
    );

    EXPECT_EQ(router.Route(request), MessageInfo({}, http::status::bad_request));
}

TEST(RouterTest, RouteWithImproperPath) {
    Router router;

    ParsedRequest request(
            url::params_encoded_view("user_id=63&resource_id=23"),
            "/video/supervideolist",
            http::verb::post,
            json::parse(R"(
                        {
                            "name": "supername",
                            "exported_from": "super",
                            "videos": ["a", "great", "many"]
                         }
                    )")
    );

    EXPECT_EQ(router.Route(request), MessageInfo({}, http::status::not_found));
}