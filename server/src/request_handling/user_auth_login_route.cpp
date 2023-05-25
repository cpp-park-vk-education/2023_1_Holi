//
// Created by Алексей on 25.05.2023.
//

#include "request_handling/user_auth_login_route.h"


MessageInfo UserAuthLoginRoute::Get(int id) {
    return {};
}

MessageInfo UserAuthLoginRoute::Post(json::value body) {
    json::object credentials;
    try {
        credentials = body.as_object();
    } catch (const std::invalid_argument &e) {
        std::cerr << "Json isnt object:" << e.what() << std::endl;
        return {{}, http::status::bad_request};
    } catch (...) {
        std::cerr << "Unexpected error with json:" << std::endl;
        return {{}, http::status::bad_request};
    }

    std::map<std::string, std::string> values;
    try {
        values["login"] = credentials.at("login").as_string();
        values["password"] = credentials.at("password").as_string();
    } catch (const std::out_of_range &e) {
        std::cerr << "Not enough data to login:" << e.what() << std::endl;
        return {{}, http::status::bad_request};
    } catch (const std::invalid_argument &e) {
        std::cerr << "Incorrect data type" << e.what() << std::endl;
        return {{}, http::status::bad_request};
    } catch (...) {
        std::cerr << "Unexpected error with json:" << std::endl;
        return {{}, http::status::bad_request};
    }

    std::string sql = R"(select * from "User" where login = ')" + values["login"] + "\'";

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

    std::string password_to_check;
    if (query.next()) {
        password_to_check = query.value("password").toString().toStdString();
    }

    if (password_to_check != values["password"]) {
        return {{}, http::status::ok};
    }

    std::vector<std::string> keys{"id", "name", "surname", "email", "login", "password"};
    json::object init;
    int i = 0;
    while(query.next() && i < keys.size()) {
        init[keys[i]] = query.value(keys[i].c_str()).toString().toStdString();
        ++i;
    }
    json::value response_body(init);
    std::cout << "\t\t--- Create json value" << std::endl;

    return {response_body, http::status::ok};

}

MessageInfo UserAuthLoginRoute::Delete(int id) {
    return {};
}