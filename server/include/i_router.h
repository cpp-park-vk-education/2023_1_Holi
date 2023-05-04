//
// Created by Алексей on 03.05.2023.
//

#pragma once

#include "namespaces.h"
#include "message_info.h"
#include "parsed_request.h"


class IRouter {
public:
    virtual MessageInfo Route(const ParsedRequest &request) = 0;

    virtual ~IRouter() = default;
};
