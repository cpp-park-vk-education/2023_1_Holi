//
// Created by Алексей on 01.05.2023.
//

#include "request_handling/video_route.h"


MessageInfo VideoRoute::Get(int id) {
//    if (id <= 0) {
//        return {{}, http::status::not_found};
//    }
//    std::string sql = R"(select * from "User" where id = )" + std::to_string(id);
//
//    QSqlQuery query;
//    try {
//        query = db_connector_->MakeQuery(sql.c_str());
//    } catch (ConditionError &e) {
//        std::cerr << e.what() << std::endl;
//        return {{}, http::status::internal_server_error};
//    } catch (...) {
//        std::cerr << "Unexpected error with DB" << std::endl;
//        return {{}, http::status::internal_server_error};
//    }
//
//    std::vector<std::string> keys{"id", "name", "surname", "email", "avatar", "login", "password"};
//    json::object init;
//    while (query.next()) {
//        for (const auto &i: keys) {
//            init[i] = query.value(i.c_str()).toString().toStdString();
//        }
//    }
//
//    json::value body(init);
//    std::cout << "Create json value" << std::endl;
//
//    return {body, http::status::ok};
}

MessageInfo VideoRoute::Post(json::value body) {
    return {};
}

MessageInfo VideoRoute::Delete(int id) {
    return {};
}