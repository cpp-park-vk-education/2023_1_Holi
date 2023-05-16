#pragma once

#include <string>
#include <memory>

#include "request.hpp"

class MainWindow;

class APIClient{
protected:
    std::string access_token_;
    int user_id_;
public:
    APIClient(std::string& access_token, int user_id):
        access_token_(access_token), user_id_(user_id) {} 

    virtual ~APIClient(){}

    virtual void GetPlaylists(MainWindow*, int) = 0;
    virtual void GetVideos() = 0;
};
