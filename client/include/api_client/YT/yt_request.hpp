#pragma once

#include "request.hpp"

class YTRequest: public Request{
public:
    YTRequest(){}

    void execute() override;
};
