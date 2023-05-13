//
// Created by Алексей on 01.05.2023.
//

#include "server/server.h"


Server::Server(
        net::io_context &ioc,
        tcp::endpoint endpoint
) :
        ioc_(ioc),
        acceptor_(net::make_strand(ioc)) {
    beast::error_code ec;

    acceptor_.open(endpoint.protocol(), ec);
    if (ec) {
        fail(ec, "open");
        return;
    }

    acceptor_.set_option(net::socket_base::reuse_address(true), ec);
    if (ec) {
        fail(ec, "set_option");
        return;
    }

    acceptor_.bind(endpoint, ec);
    if (ec) {
        fail(ec, "bind");
        return;
    }

    acceptor_.listen(
            net::socket_base::max_listen_connections, ec);
    if (ec) {
        fail(ec, "listen");
        return;
    }
}

void Server::Run() {
    DoAccept();
}

void Server::DoAccept() {
    acceptor_.async_accept(
            net::make_strand(ioc_),
            beast::bind_front_handler(
                    &Server::OnAccept,
                    shared_from_this()));
}

void Server::OnAccept(beast::error_code ec, tcp::socket socket) {
    if (ec) {
        fail(ec, "accept");
        return; // To avoid infinite loop
    } else {
        std::make_shared<Session>(
                std::move(socket))->Start();
    }

    DoAccept();
}
