//
// Created by Алексей on 04.05.2023.
//

#pragma once

#include "client/errors.h"
#include "message_info.h"
#include "namespaces.h"


class IResponseHandler {
public:
    virtual MessageInfo Handle(http::response<http::string_body> &&response) = 0;

    virtual ~IResponseHandler() = default;
};
