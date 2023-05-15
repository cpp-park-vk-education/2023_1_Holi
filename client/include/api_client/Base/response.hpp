#pragma once

#include <vector>
#include <string>

#include "message_info.h"

//todo: string поменять на Json::value
class Response{
private:
    MessageInfo result_;
public:
    Response(){}
    virtual ~Response(){}

    void get_response(MessageInfo result){ result_ = result; }  //Этот метод вызывается от RequestMaker'a
    
    virtual void parse_result() = 0;
};
