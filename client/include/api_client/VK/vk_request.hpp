#pragma once

#include "request.hpp"
#include "request_maker/requestmaker_https.hpp"
#include <memory>

class VKRequest : public Request {
public:
    VKRequest(){}

    void execute() override;
};
