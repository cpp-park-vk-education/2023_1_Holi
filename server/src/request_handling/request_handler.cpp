//
// Created by Алексей on 01.05.2023.
//

#include "request_handling/request_handler.h"
#include "request_handling/parsed_request.h"

#include <boost/beast/http.hpp>


http::response<http::string_body> RequestHandler::Handle(http::request<http::string_body> &&request) {
    request_ = std::move(request);
    ParsedRequest parsed_request;

//    ParseHeader();
//    if (!authorizer_->IsAuthorized()) {
//        authorizer_->Authorize();
//        return CreateResponse(http::status::unauthorized);
//    }

    parsed_request.method_ = request_.method();

    auto is_result = ParseUrl();
    url::url parsed_url;
    if (is_result) {
        parsed_url = *is_result;
    } else {
        return CreateResponse(http::status::bad_request);
    }

    parsed_request.path_ = parsed_url.path();
    parsed_request.parameters_ = parsed_url.params();

    boost::system::error_code ec;
    parsed_request.body_ = request_.body().empty() ? json::parse("{}", ec) : json::parse(request_.body(), ec);
    if (ec) {
        std::cerr << ec.message() << std::endl;
        return CreateResponse(http::status::bad_request);
    }
    if (parsed_request.method_ == http::verb::post && parsed_request.body_ == json::parse("{}")) {
        return CreateResponse(http::status::bad_request);
    }

    MessageInfo message_info = router_->Route(parsed_request);
    return CreateResponse(message_info.status_, json::serialize(message_info.body_));
}

void RequestHandler::ParseHeader() {

}

json::value RequestHandler::ParseBody() {
    return {};
}

http::response<http::string_body> RequestHandler::CreateResponse(http::status status, const std::string &body) {
    http::response<http::string_body> response{status, request_.version()};

    response.set(http::field::host, "localhost");
    response.set(http::field::server, BOOST_BEAST_VERSION_STRING);
    response.keep_alive(request_.keep_alive());
    response.set(http::field::content_length, std::to_string(body.length()));
    response.set(http::field::content_type, "application/json");
    response.body() = body;
    response.prepare_payload();

    return response;
}

url::result<url::url> RequestHandler::ParseUrl() {
    return url::parse_origin_form(request_.target());
}