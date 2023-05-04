//
// Created by Алексей on 01.05.2023.
//

#pragma once

#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/http/message.hpp>
#include <boost/beast/version.hpp>
#include <queue>

#include "namespaces.h"
#include "room.h"


class Session : public std::enable_shared_from_this<Session> {
private:
    std::vector<std::shared_ptr<Room>> rooms_;
    std::queue<http::request<http::string_body>> write_messages_;
    beast::tcp_stream stream_;
    http::request<http::string_body> request_;

public:
    void Start();

    void DoRead();

    void OnRead(beast::error_code ec, std::size_t bytes_transferred);

    void SendResponse(http::message_generator &&message);

    void OnWrite(
            bool keep_alive,
            beast::error_code ec,
            std::size_t bytes_transferred
    );

    void DoClose();

};
