//
// Created by Алексей on 01.05.2023.
//

#pragma once

#include <boost/beast/http/message_generator.hpp>

#include "namespaces.h"


class IRequestHandler {
public:
    virtual http::response<http::string_body> Handle(http::request<http::string_body> &&request) = 0;

    virtual ~IRequestHandler() = default;
};