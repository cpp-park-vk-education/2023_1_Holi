#pragma once

#include "request.hpp"

class YTRequest: public Request{
public:
    YTRequest(std::unique_ptr<Response> response_ptr):
        Request(std::move(response_ptr)) {}

    void execute() override;
};