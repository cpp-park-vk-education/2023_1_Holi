//
// Created by Алексей on 25.05.2023.
//

#pragma once

#include "request_handling/i_route.h"

#include <vector>
#include <string>


class UserAuthLoginRoute : public IRoute {
private:
    std::unique_ptr<IDbConnectorTmp> db_connector_;

public:
    explicit UserAuthLoginRoute(std::unique_ptr<IDbConnectorTmp> db_connector = nullptr) :
            db_connector_(std::make_unique<DbConnectorTmp>()) {}

    MessageInfo Get(int id) override;

    MessageInfo Post(json::value body) override;

    MessageInfo Delete(int id) override;
};
