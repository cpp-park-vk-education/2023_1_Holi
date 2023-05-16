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
    Response() {}
    virtual ~Response(){}   

    void get_response(MessageInfo result){ 
        result_ = result; 
        parse_result();
    }  //Этот метод вызывается от RequestMaker'a

    virtual void parse_result() = 0;
};

#include "gui/mainwindow.h"

/*
void MP_VK_getAlbums(MessageInfo* info);  -> 1
void MP_VK_getVideo(MessageInfo* info);   -> 2

void MP_YT_getAlbums(MessageInfo* info);  -> 3
void MP_YT_getVideo(MessageInfo* info);   -> 4
*/
