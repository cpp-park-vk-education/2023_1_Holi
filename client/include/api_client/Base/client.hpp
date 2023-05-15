#pragma once

#include <string>
#include <memory>

#include "response.hpp"
#include "request.hpp"

class APIClient{
protected:
    std::string access_token_;
    int user_id_;

    std::unique_ptr<Request> request_ptr_;
public:
    APIClient(std::string& access_token, int user_id):
        access_token_(access_token), user_id_(user_id) {} 

    virtual ~APIClient(){}

    virtual void GetPlaylists() = 0;
    virtual void GetVideos() = 0;
};