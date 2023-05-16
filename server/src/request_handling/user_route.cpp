//
// Created by Алексей on 01.05.2023.
//

#include "request_handling/user_route.h"


MessageInfo UserRoute::Get(int id) {
    if (id <= 0) {
        std::cerr << "Negative id" << std::endl;
        return {{}, http::status::not_found};
    }

    std::string sql = R"(select * from "User" where id = )" + std::to_string(id);

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

    std::vector<std::string> keys{"id", "name", "surname", "email", "login", "password"};
    json::object init;
    while (query.next()) {
        for (const auto &i: keys) {
            init[i] = query.value(i.c_str()).toString().toStdString();
        }
    }

    json::value body(init);
    std::cout << "\t\t--- Create json value" << std::endl;

    return {body, http::status::ok};
}

MessageInfo UserRoute::Post(json::value body) {
    return {};
}

MessageInfo UserRoute::Delete(int id) {
    return {};
}
