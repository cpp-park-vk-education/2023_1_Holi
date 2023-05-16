//
// Created by Алексей on 09.05.2023.
//

#pragma once

#include <boost/beast/ssl.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

#include "i_client.h"
#include "message_info.h"
#include "response_handler.h"
#include "root_certificates.hpp"


class ClientHttps : public IClient {
public:
    explicit ClientHttps(http::request<http::string_body> request);

    void Run(
            const std::string &host,
            const std::string &port,
            const std::string &target
    ) override;

    MessageInfo GetResponse() override;

    ~ClientHttps() override {
        std::cerr << "HttpsClient destruct" << std::endl;
    }

private:
    net::io_context ioc_;  // порядок важен, не менять
    ssl::context ctx_;
    tcp::resolver resolver_;
    beast::ssl_stream<beast::tcp_stream> stream_;
    http::response<http::string_body> response_;
    http::request<http::string_body> request_;
    beast::flat_buffer buffer_;
    std::unique_ptr<IResponseHandler> response_handler_;

private:
    void Write();

};

