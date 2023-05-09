//
// Created by Алексей on 09.05.2023.
//

#pragma once

#include "i_response_handler.h"

class ResponseHandler : public IResponseHandler {
public:
    MessageInfo Handle(http::response<http::string_body> &&response);

private:
    void ParseBody();
};
