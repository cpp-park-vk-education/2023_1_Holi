//
// Created by Алексей on 09.05.2023.
//

#pragma once

#include "message_info.h"


class IResponseHandler {
public:
    MessageInfo Handle(http::response<http::string_body> &&response);
};
