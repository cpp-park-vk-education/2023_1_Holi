//
// Created by Алексей on 04.05.2023.
//

#pragma once

#include "i_response_handler.h"


class ResponseHandler : public IResponseHandler {
public:
//    explicit RespHandler(std::unique_ptr<IRouter> router) : router_(router.release()) {}

    MessageInfo Handle(http::response<http::string_body> &&response) override;

private:
    void ParseBody();
};
