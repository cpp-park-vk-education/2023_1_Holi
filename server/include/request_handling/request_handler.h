//
// Created by Алексей on 01.05.2023.
//

#pragma once

#include "request_handling/i_request_handler.h"
#include "namespaces.h"
#include "router.h"


class RequestHandler : public IRequestHandler {
private:
//    json::value body_;
//    http::response<http::string_body> response_;
//    std::weak_ptr<Session> session_;

    std::unique_ptr<IRouter> router_;

public:
    explicit RequestHandler(std::unique_ptr<IRouter> router) : router_(router.release()) {}

    http::response<http::string_body> Handle(http::request<http::string_body> &&request) override;

private:
    void ParseHeader();

    void ParseBody();

    void CreateResponse();

    void ParseUrl();
};
