//
// Created by Алексей on 01.05.2023.
//

#include "request_handling/user_route.h"


MessageInfo UserRoute::Get(int id) {
    std::string sql = R"(select * from "User" where id == )" + std::to_string(id);
    auto query = db_connector_->MakeQuery(sql.c_str());

    std::vector<std::string> keys{"id", "name", "surname", "email", "avatar", "login", "password"};
    json::object init;
    while (query.next()) {
        for (const auto &i: keys) {
            init[i] = query.value("id").toString().toStdString();
        }
    }

    json::value body(init);
    std::cout << "Create json value" << std::endl;

    return {body, http::status::ok};
}

MessageInfo UserRoute::Post(json::value body) {
    return {};
}

MessageInfo UserRoute::Delete(int id) {
    return {};
}