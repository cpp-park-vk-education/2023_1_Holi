//
// Created by Алексей on 01.05.2023.
//

#pragma once

#include "request_handling/i_route.h"

#include <vector>
#include <string>


class UserRoute : public IRoute {
private:
    int user_id_;
    std::unique_ptr<IDbConnectorTmp> db_connector_;

public:
    explicit UserRoute(int user_id = 0, std::unique_ptr<IDbConnectorTmp> db_connector = nullptr) :
            user_id_(user_id),
            db_connector_(std::make_unique<DbConnectorTmp>()) {}

    MessageInfo Get(int id) override;

    MessageInfo Post(json::value body) override;

    MessageInfo Delete(int id) override;
};
