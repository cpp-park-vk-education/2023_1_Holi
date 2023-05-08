//
// Created by Алексей on 03.05.2023.
//

#include <gtest/gtest.h>

#include "request_handling/request_handler.h"
#include "request_handling/router.h"


http::request<http::string_body>
GetRequest(const std::string &target, http::verb method, const std::string &body = "") {
    http::request<http::string_body> request;

    request.version(11);
    request.method(method);
    request.target(target);
    request.set(http::field::host, "localhost");
    request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    request.set(http::field::content_type, "application/json");
    request.set(http::field::content_length, std::to_string(body.length()));
    request.keep_alive(true);
    request.body() = body;
    request.prepare_payload();

    return request;

}

http::response<http::string_body>
GetResponse(const http::request<http::string_body> &request,
            http::status status, const std::string &body = "") {

    http::response<http::string_body> response{status, request.version()};

    response.set(http::field::host, "localhost");
    response.set(http::field::server, BOOST_BEAST_VERSION_STRING);
    response.keep_alive(request.keep_alive());
    response.set(http::field::content_length, std::to_string(body.length()));
    response.set(http::field::content_type, "application/json");
    response.body() = body;
    response.prepare_payload();

    return response;
}


class StabFailRouter : public IRouter {
public:
    MessageInfo Route(const ParsedRequest &request) override {
        return {{}, http::status::bad_request};
    };
};

class StabSuccessRouter : public IRouter {
public:
    MessageInfo Route(const ParsedRequest &request) override {
        return {json::parse(R"(
            {
                "name": "name",
                "image": "image",
                "exported_from": "exported_from",
                "user": "6",
                "playlists": ["12", "2", "43"]
            }
        )"), http::status::ok };
    };
};


TEST(RequestHandlerTest, InvalidJsonBody) {
    RequestHandler handler(std::make_unique<StabFailRouter>());

    std::string body = R"(
                    "name": "name"
                    "surname": "surname"
                    "email": "email"
                    "avatar": "avatar"
                    login: "login"
                    "password": "password",
                })";

    auto request = GetRequest("/user", http::verb::post, body);

    EXPECT_EQ(handler.Handle(std::move(request)).result(), http::status::bad_request);
}

TEST(RequestHandlerTest, InvalidPath) {
    RequestHandler handler(std::make_unique<StabFailRouter>());

    std::string body = R"({
                    "name": "name"
                    "surname": "surname"
                    "email": "email"
                    "avatar": "avatar"
                    login: "login"
                    "password": "password",
                })";

    auto request = GetRequest("#####  <<< >>>  %%%%", http::verb::post, body);

    EXPECT_EQ(handler.Handle(std::move(request)).result(), http::status::bad_request);
}

TEST(RequestHandlerTest, PostEmptyBody) {
    RequestHandler handler(std::make_unique<StabFailRouter>());

    auto request = GetRequest("/video", http::verb::post);

    ASSERT_NO_THROW(handler.Handle(std::move(request)));
    EXPECT_EQ(handler.Handle(std::move(request)).result(), http::status::bad_request);
}

TEST(RequestHandlerTest, CommonRequest) {
    RequestHandler handler(std::make_unique<StabSuccessRouter>());

    std::string body = R"(
        {
            "name": "name",
            "image": "image",
            "exported_from": "exported_from",
            "user": "6",
            "playlists": ["12", "2", "43"]
        }
    )";

    auto request = GetRequest("/video", http::verb::post, body);
    auto request_copy = request;

    auto actual = handler.Handle(std::move(request_copy));

    EXPECT_EQ(actual.result(), http::status::ok);
    EXPECT_EQ(json::parse(actual.body()), json::parse(body));
}
