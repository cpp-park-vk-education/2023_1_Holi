#pragma once
#include <memory>
#include <string>
#include <map>
#include <thread>
#include <boost/beast/ssl.hpp>

#include "client/client_http.h"
#include "client/message_info.h"

class MainWindow;

class RequestMakerHttp {
public:
    RequestMakerHttp(const std::string& target, std::unique_ptr<MainWindow> window ) : 
    target_(target), window_(std::move(window))
    {
        host_ = "localhost";
        port_ = "8080";
    }

    RequestMakerHttp(const std::string& target) : target_(target) 
    {
        host_ = "localhost";
        port_ = "8080";
    }
    ~RequestMakerHttp() {
        std::cerr << "RequestMakerHttp destruct" << std::endl;
    }
    void Get();
    void Post(std::string & body);
    void Delete();
    private:
    void CallBack();

    std::unique_ptr<MainWindow> window_;
    std::unique_ptr<ClientHttp> client_;
    std::string host_;
    std::string port_;
    std::string target_;
};

#include "gui/mainwindow.h"