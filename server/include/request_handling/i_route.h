//
// Created by Алексей on 01.05.2023.
//

#pragma once

#include <memory>
#include <exception>

#include "db_tmp/db_connector.h"
#include "message_info.h"


class IRoute {
public:
    virtual MessageInfo Get(int id) = 0;

    virtual MessageInfo Post(json::value body) = 0;

    virtual MessageInfo Delete(int id) = 0;

    virtual ~IRoute() = default;
};