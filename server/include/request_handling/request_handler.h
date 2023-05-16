//
// Created by Алексей on 01.05.2023.
//

#pragma once

#include "auth/authorizer.h"
#include "request_handling/i_request_handler.h"
#include "namespaces.h"
#include "router.h"


class RequestHandler : public IRequestHandler {
private:
    std::unique_ptr<IAuthorizer> authorizer_;
    http::request<http::string_body> request_;
    std::unique_ptr<IRouter> router_;

public:
    RequestHandler() : authorizer_(std::make_unique<Authorizer>()), router_(std::make_unique<Router>()) {}

    explicit RequestHandler(std::unique_ptr<IRouter> router) : router_(router.release()) {}

    http::response<http::string_body> Handle(http::request<http::string_body> &&request) override;

private:
    http::response<http::string_body> CreateResponse(http::status status, const std::string &body = "");
};
