//
// Created by Алексей on 03.05.2023.
//

#include <gtest/gtest.h>

#include "request_handling/router.h"
#include "request_handling/parsed_request.h"


struct StabVideoListRoute : IRoute {
    MessageInfo Get(int id) override {
        return {
                json::parse(R"(
                        {
                            "name": "name",
                            "image": "image",
                            "exported_from": "exported_from",
                            "user": "6",
                            "videos": ["13", "24", "11"]
                         }
                    )"),
                http::status::ok
        };
    }

    MessageInfo Post(json::value body) override { return {{}, http::status::bad_request}; };

    MessageInfo Delete(int id) override { return {}; };
};

struct StabVideoRoute : IRoute {
    MessageInfo Get(int id) override { return {{}, http::status::bad_request}; };

    MessageInfo Post(json::value body) override { return {{}, http::status::not_found}; };

    MessageInfo Delete(int id) override { return {}; };
};


TEST(RouterTest, RouteWithNoParams) {
    Router router(std::make_unique<StabVideoRoute>());

    ParsedRequest request(
            {},
            "/video",
            http::verb::get
    );

    EXPECT_EQ(router.Route(request), MessageInfo({}, http::status::bad_request));
}

TEST(RouterTest, RouteWithInvalidParams) {
    Router router(std::make_unique<StabVideoRoute>());

    ParsedRequest request(
            urls::params_encoded_view("user_id=Artemij&resource_id=23"),
            "/video",
            http::verb::get
    );

    EXPECT_EQ(router.Route(request), MessageInfo({}, http::status::bad_request));
}

TEST(RouterTest, RouteWithCommonParams) {
    Router router(std::make_unique<StabVideoListRoute>());

    ParsedRequest request(
            urls::params_encoded_view("user_id=43&resource_id=23"),
            "/video/list",
            http::verb::get
    );

    MessageInfo expected(json::parse(R"(
            {
                "name": "name",
                "image": "image",
                "exported_from": "exported_from",
                "user": "6",
                "videos": ["13", "24", "11"]
            }
        )"),
                         http::status::ok
    );

    EXPECT_EQ(router.Route(request), expected);
}

TEST(RouterTest, RouteWithNoPath) {
    Router router(std::make_unique<StabVideoListRoute>());

    ParsedRequest request(
            urls::params_encoded_view("user_id=63&resource_id=23"),
            "",
            http::verb::post,
            json::parse(R"(
                        {
                            "name": "name",
                            "image": "image",
                            "exported_from": "exported_from",
                            "user": "6",
                            "videos": ["13", "24", "11"]
                         }
                    )")
    );

    EXPECT_EQ(router.Route(request), MessageInfo({}, http::status::bad_request));
}

TEST(RouterTest, RouteWithImproperPath) {
    Router router(std::make_unique<StabVideoRoute>());

    ParsedRequest request(
            urls::params_encoded_view("user_id=63&resource_id=23"),
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