//
// Created by Алексей on 04.05.2023.
//

#include "request_maker/response_handler.h"

#include <boost/beast/http.hpp>


MessageInfo ResponseHandler::Handle(http::response<http::string_body> &&response) {
    return {};
}

void ResponseHandler::ParseBody() {

}
