#pragma once
#include <memory>
#include <string>
#include <map>
#include <thread>
#include <boost/beast/ssl.hpp>
#include "client_https.h"
#include "responce.h"
#include "message_info.h"

class RequestMaker {
public:
    RequestMaker(const std::string& host, const std::string& target, std::unique_ptr<Responce> responce ) : 
    (host_(host), target_(target), responce_(std::move(responce)))
    {
        port_ = "443";
    }
    void Get();
    void Post(json::value body);
    void Delete();
    private:
    void CallBack(http::request<http::string_body> request);

    std::unique_ptr<Response> response_;
    std::unique_ptr<Client> client_;
    std::string host_;
    std::string port_;
    std::string target_;
}