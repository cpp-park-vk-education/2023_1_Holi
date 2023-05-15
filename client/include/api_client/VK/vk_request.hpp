#pragma once

#include "request.hpp"
#include "requestmaker_https.hpp"
#include <memory>

class VKRequest : public Request {
public:
    VKRequest(){}

    void execute() override;
};
