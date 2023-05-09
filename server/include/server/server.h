//
// Created by Алексей on 01.05.2023.
//

#pragma once

#include "namespaces.h"
#include "session.h"


class Server : public std::enable_shared_from_this<Server> {
private:
    net::io_context &ioc_;
    tcp::acceptor acceptor_;

public:
    Server(
            net::io_context &ioc,
            tcp::endpoint endpoint
    );


    void Run();

    void Stop();

private:
    void DoAccept();

    void OnAccept(beast::error_code ec, tcp::socket socket);
};
