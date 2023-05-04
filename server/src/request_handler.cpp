//
// Created by Алексей on 01.05.2023.
//

#include "request_handler.h"

#include <boost/beast/http.hpp>

http::response<http::string_body> RequestHandler::Handle(http::request<http::string_body> &&request) {
    http::response<http::string_body> result;
    result.body() = "{}";
    return result;
}

void RequestHandler::ParseHeader() {

}

void RequestHandler::ParseBody() {

}

void RequestHandler::CreateResponse() {

}

void RequestHandler::ParseUrl() {

}