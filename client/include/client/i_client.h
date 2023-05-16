//
// Created by Алексей on 14.05.2023.
//

#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

//#include "root_certificates.hpp"
#include "message_info.h"
#include "namespaces.h"


class IClient {
public:
    virtual void Run(
            const std::string &host,
            const std::string &port,
            const std::string &target
    ) = 0;


    virtual MessageInfo GetResponse() = 0;

    virtual ~IClient() = default;
};
