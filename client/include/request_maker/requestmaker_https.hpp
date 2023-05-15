#pragma once
#include <memory>
#include <string>
#include <map>
#include <thread>
#include <boost/beast/ssl.hpp>

#include "client/client_https.h"
#include "api_client/Base/response.hpp"
#include "client/message_info.h"

class RequestMaker {
public:
    RequestMaker(const std::string& host, const std::string& target, std::unique_ptr<Response> response ) : 
    host_(host), target_(target), response_(std::move(response))
    {
        port_ = "443";
    }
    void Get();
    void Post(json::value body);
    void Delete();
    private:
    void CallBack(http::request<http::string_body> request);

    std::unique_ptr<Response> response_;
    std::unique_ptr<IClient> client_;
    std::string host_;
    std::string port_;
    std::string target_;
};