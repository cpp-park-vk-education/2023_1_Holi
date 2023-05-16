//
// Created by Алексей on 01.05.2023.
//

#pragma once

#include "namespaces.h"


class IAuthorizer {
public:
    virtual json::value Authorize() = 0;

    virtual json::value Register() = 0;

    virtual bool IsAuthorized() = 0;

    virtual ~IAuthorizer() = default;
};