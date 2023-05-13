//
// Created by Алексей on 09.05.2023.
//

#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/strand.hpp>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>

#include "message_info.h"
#include "namespaces.h"
#include "response_handler.h"


class Client {
public:
    explicit Client(net::io_context &ioc) :
            resolver_(net::make_strand(ioc)),
            stream_(net::make_strand(ioc)),
            response_handler(std::make_unique<ResponseHandler>()) {}

    void Close();

    void Run(
            const std::string &host,
            const std::string &port,
            const std::string &target
    );

    void Write();

    MessageInfo GetResponse();

private:
    beast::tcp_stream stream_;
    tcp::resolver resolver_;
    http::response<http::string_body> response_;
    http::request<http::string_body> request_;
    beast::flat_buffer buffer_;
    std::unique_ptr<IResponseHandler> response_handler;
};

