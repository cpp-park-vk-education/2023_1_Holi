#pragma once

#include "request.hpp"
#include "request_maker/requestmaker_https.hpp"
#include <memory>


class VKRequest : public Request {
public:
    VKRequest() {}

    ~VKRequest() override {
        std::cerr << "VKRequest destruct" << std::endl;
    }

    void execute() override;

private:
    std::unique_ptr<RequestMaker> request_maker;
};
