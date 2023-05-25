//
// Created by Алексей on 25.05.2023.
//

#include "request_handling/user_auth_check_route.h"


MessageInfo UserAuthCheckRoute::Get(int id) {
    return {};
}
MessageInfo UserAuthCheckRoute::Get(const std::string &param) {
    std::string sql = R"(select * from "User" where login = ')" + param + "\'";

    QSqlQuery query;
    try {
        query = QSqlQuery(db_connector_->Connect());
        query.prepare(sql.c_str());
        query = db_connector_->MakeQuery(std::move(query));
    } catch (ConditionError &e) {
        std::cerr << e.what() << std::endl;
        return {{}, http::status::internal_server_error};
    } catch (...) {
        std::cerr << "Unexpected error with DB" << std::endl;
        return {{}, http::status::internal_server_error};
    }

    std::vector<std::string> keys{"id"};
    json::object init;
    while (query.next()) {
        for (const auto &i: keys) {
            init[i] = query.value(i.c_str()).toString().toStdString();
        }
    }

    json::value body(init);
    std::cout << "\t\t--- Create json value" << std::endl;

    return {body, http::status::ok};
};

MessageInfo UserAuthCheckRoute::Post(json::value body) {
    return {};
}

MessageInfo UserAuthCheckRoute::Delete(int id) {
    return {};
}
