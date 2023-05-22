#pragma once

#include "request.hpp"
#include "request_maker/requestmaker_https.hpp"
#include <memory>


class YTRequest : public Request {
public:
    YTRequest() {}

    ~YTRequest() override {
        std::cerr << "VKRequest destruct" << std::endl;
    }

    void execute(MainWindow*, int) override;

private:
    std::unique_ptr<RequestMaker> request_maker;
};