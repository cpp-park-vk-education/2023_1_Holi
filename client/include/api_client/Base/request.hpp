#pragma once

#include "response.hpp"
#include <map>
#include <memory>
#include <string>

#include "gui/mainwindow.h"
class Request {
protected:
    std::string access_token_;
    std::string method_;
    std::map<std::string, std::string> params_;
public:
    Request(){}
    virtual ~Request() {}

    void setAccessToken(std::string access_token) {
        access_token_ = access_token;
    }
    void setMethod(std::string method) { 
        method_ = method; 
    }
    void setParams(std::map<std::string, std::string> params) {
        params_ = params;
    }
    MainWindow mw;
    virtual void execute() = 0;
};
