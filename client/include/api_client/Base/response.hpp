#pragma once

#include <vector>
#include <string>

#include "message_info.h"

class Response{
protected:
    MessageInfo result_;
public:
    Response(){}
    virtual ~Response(){}   

    void get_response(MessageInfo result){ 
        result_ = result; 
        parse_result();
    }  //Этот метод вызывается от RequestMaker'a
    
    virtual void parse_result() = 0;
};
