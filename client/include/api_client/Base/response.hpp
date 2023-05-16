#pragma once

#include <vector>
#include <string>
#include <map>
#include "client/message_info.h"

class MainWindow;


class Response{
protected:
    MessageInfo result_;
    MainWindow* window_;
    int flag_;
public:
    Response(MainWindow* window, int flag): window_(window), flag_(flag) {}
    virtual ~Response(){}   

    void get_response(MessageInfo result){ 
        result_ = result; 
        parse_result();
    }  //Этот метод вызывается от RequestMaker'a

    MainWindow *mw;

    virtual void parse_result() = 0;
};
