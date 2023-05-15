//
// Created by Алексей on 09.05.2023.
//

#pragma once

#include <boost/beast/ssl.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

#include "i_client.h"
#include "message_info.h"
#include "response_handler.h"


class ClientHttps : public IClient {
public:
    ClientHttps(net::io_context &ioc, ssl::context& ctx, http::request<http::string_body> request) :
            resolver_(net::make_strand(ioc)),
            stream_(net::make_strand(ioc), ctx),
            response_handler(std::make_unique<ResponseHandler>()),
            request_(std::move(request)) {}

    void Run(
            const std::string &host,
            const std::string &port,
            const std::string &target
    ) override;

    MessageInfo GetResponse() override;

private:
    beast::ssl_stream<beast::tcp_stream> stream_;
    tcp::resolver resolver_;
    http::response<http::string_body> response_;
    http::request<http::string_body> request_;
    beast::flat_buffer buffer_;
    std::unique_ptr<IResponseHandler> response_handler;

private:
    void Write();

};

