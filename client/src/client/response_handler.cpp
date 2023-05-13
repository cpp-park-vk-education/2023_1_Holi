//
// Created by Алексей on 04.05.2023.
//

#include "client/response_handler.h"

#include <boost/beast/http.hpp>

//    http::response<http::string_body> response{status, request.version()};
//
//    response.set(http::field::host, "localhost");
//    response.set(http::field::server, BOOST_BEAST_VERSION_STRING);
//    response.keep_alive(request.keep_alive());
//    response.set(http::field::content_length, std::to_string(body.length()));
//    response.set(http::field::content_type, "application/json");
//    response.body() = body;
//    response.prepare_payload();

MessageInfo ResponseHandler::Handle(http::response<http::string_body> &&response) {
    response_ = std::move(response);

    MessageInfo message_info;

    message_info.status_ = response_.result();
//    parsed_request.body_ = request_.body().empty() ? json::parse("{}", ec) : json::parse(request_.body(), ec);
//    if (ec) {
//        std::cerr << ec.message() << std::endl;
//        return CreateResponse(http::status::bad_request);
//    }
//    if (parsed_request.method_ == http::verb::post && parsed_request.body_ == json::parse("{}")) {
//        return CreateResponse(http::status::bad_request);
//    }
    return {};
}

void ResponseHandler::ParseBody() {

}
