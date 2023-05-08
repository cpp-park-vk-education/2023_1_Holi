//
// Created by Алексей on 01.05.2023.
//

#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>


#include "namespaces.h"


class Server {
private:
//    net::io_context& ioc_;
    tcp::acceptor acceptor_;

public:
    void Run();
    void Stop();
};
