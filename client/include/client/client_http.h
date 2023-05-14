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
    explicit ClientHttp(net::io_context &ioc) :
            resolver_(net::make_strand(ioc)),
            stream_(net::make_strand(ioc)),
            response_handler(std::make_unique<ResponseHandler>()) {}

    void Run(
            const std::string &host,
            const std::string &port,
            const std::string &target
    ) override;

    MessageInfo GetResponse() override;

private:
    beast::tcp_stream stream_;
    tcp::resolver resolver_;
    http::response<http::string_body> response_;
    http::request<http::string_body> request_;
    beast::flat_buffer buffer_;
    std::unique_ptr<IResponseHandler> response_handler;

private:
    void Write();

};

