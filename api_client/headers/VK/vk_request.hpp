#pragma once

#include "request.hpp"

class VKRequest: public Request{
public:
    VKRequest(std::unique_ptr<Response> response_ptr):
        Request(std::move(response_ptr)) {}

    void execute() override;
};