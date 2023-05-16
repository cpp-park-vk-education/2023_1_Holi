//
// Created by Алексей on 04.05.2023.
//

#include <gtest/gtest.h>

#include "client/errors.h"
#include "client/response_handler.h"


http::response<http::string_body>
GetResponse(http::status status, const std::string &body = "") {

    http::response<http::string_body> response{status, 11};

    response.set(http::field::host, "localhost");
    response.set(http::field::server, BOOST_BEAST_VERSION_STRING);
    response.keep_alive(true);
    response.set(http::field::content_length, std::to_string(body.length()));
    response.set(http::field::content_type, "application/json");
    response.body() = body;
    response.prepare_payload();

    return response;
}


TEST(ResponseHandlerTest, OkStatus) {
    std::string body = R"(
        {
            "name": "name",
            "image": "image",
            "exported_from": "exported_from",
            "user": "6",
            "playlists": ["12", "2", "43"]
        }
    )";

    auto response = GetResponse(http::status::ok, body);

    auto expected = MessageInfo{json::parse(body), http::status::ok};
    ResponseHandler handler;
    EXPECT_EQ(handler.Handle(std::move(response)), expected);
}

TEST(ResponseHandlerTest, BadStatus) {
    auto response = GetResponse(http::status::bad_request, {});

    auto expected = MessageInfo{json::value{}, http::status::bad_request};
    ResponseHandler handler;
    EXPECT_EQ(handler.Handle(std::move(response)), expected);
}

TEST(ResponseHandlerTest, EmptyBody) {
    auto response_for_throw_check = GetResponse(http::status::ok);
    auto response = GetResponse(http::status::ok);

    auto expected = MessageInfo{json::value{}, http::status::ok};
    ResponseHandler handler;

    EXPECT_NO_THROW(handler.Handle(std::move(response_for_throw_check)));
    EXPECT_EQ(handler.Handle(std::move(response)), expected);
}

TEST(ResponseHandlerTest, InvalidJson) {
    std::string body = R"(
            "name": "name"
            "image": "image"
            "exported_from": "exported_from"
            "user": "6"
            "playlists": ["12", "2", "43"]
        }
    )";

    auto response = GetResponse(http::status::ok, body);

    ResponseHandler handler;
    EXPECT_THROW(handler.Handle(std::move(response)), InvalidBodyError);
}
