//
// Created by Алексей on 09.05.2023.
//

#pragma once

#include "message_info.h"
#include "namespaces.h"


class Client {
public:
    explicit Client(net::io_context &io_context);

    void Close();

    void Run(
            const std::string &host,
            const std::string &port,
            const std::string &target
    );

    void Write(http::request<http::string_body> request);

    MessageInfo GetResponse();

private:
    void Resolve();

    void Connect();

private:
    net::io_context &io_context_;
    beast::tcp_stream stream_;
    tcp::resolver resolver_;
    http::response<http::dynamic_body> response_;
};


