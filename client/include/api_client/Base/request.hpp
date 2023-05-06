#pragma once

#include <map>
#include <string>
#include "response.hpp"


class Request{
protected:
    std::string access_token_;
    std::string method_;
    std::map<std::string, std::string> params_; 
    //указатель на объект RequestMaker'a
    //std::unique_ptr<IRequestMaker> request_maker_ptr;
    std::unique_ptr<Response> response_ptr_;
public:
    Request(){}

    Request(std::unique_ptr<Response> response_ptr): //todo: получить в параметры указатель на request_maker и инициаллизировать
        response_ptr_(std::move(response_ptr)) {}
    
    virtual ~Request(){}

    void setAccessToken(std::string access_token) { access_token_ = access_token; }
    void setMethod(std::string method) { method_ = method; }
    void setParams(std::map<std::string, std::string> params) { params_ = params; }

    virtual void execute() = 0;
};