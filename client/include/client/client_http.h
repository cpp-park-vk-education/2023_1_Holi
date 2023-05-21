//
// Created by Алексей on 09.05.2023.
//

#pragma once

#include <boost/asio/strand.hpp>
#include <chrono>
#include <functional>
#include <memory>

#include "i_client.h"
#include "message_info.h"
#include "response_handler.h"


class ClientHttp : public IClient {
public:
    ClientHttp(http::request<http::string_body> request) :
            resolver_(net::make_strand(ioc_)),
            stream_(net::make_strand(ioc_)),
            response_handler_(std::make_unique<ResponseHandler>()) {}

    void Run(
            const std::string &host,
            const std::string &port,
            const std::string &target
    ) override;

    MessageInfo GetResponse() override;

private:
    net::io_context ioc_;
    tcp::resolver resolver_;
    beast::tcp_stream stream_;
    http::request<http::string_body> request_;
    http::response<http::string_body> response_;
    beast::flat_buffer buffer_;
    std::unique_ptr<IResponseHandler> response_handler_;

private:
    void Write();

};

