//
// Created by Алексей on 04.05.2023.
//

#include "client/response_handler.h"

#include <boost/beast/http.hpp>

MessageInfo ResponseHandler::Handle(http::response<http::string_body> &&response) {
    response_ = std::move(response);

    MessageInfo message_info;

    message_info.status_ = response_.result();

    boost::system::error_code ec;
    message_info.body_ = response_.body().empty() ? json::value{} : json::parse(response_.body(), ec);
    if (ec) {
        std::cerr << ec.message() << std::endl;
        message_info.body_ = json::value{};
        throw InvalidBodyError(ec.message());
    }

    return message_info;
}
