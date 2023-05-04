//
// Created by Алексей on 01.05.2023.
//

#pragma once

#include <memory>

#include "i_db_model.h"
#include "message_info.h"


class IRoute {
public:
    virtual MessageInfo Get(int id) = 0;

    virtual MessageInfo Post(json::value body) = 0;

    virtual MessageInfo Delete(int id) = 0;

    virtual ~IRoute() = default;
};