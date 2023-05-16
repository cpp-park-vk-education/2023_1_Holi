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
    if (user_id_ <= 0) {
        std::cerr << "Non-positive  id" << std::endl;
        return {{}, http::status::not_found};
    }

    // todo check json empty
    json::object video_info;
    try {
        video_info = body.as_object();
    } catch (const std::invalid_argument &e) {
        std::cerr << "Json isnt object:" << e.what() << std::endl;
        return {{}, http::status::bad_request};
    } catch (...) {
        std::cerr << "Unexpected error with json:" << std::endl;
        return {{}, http::status::bad_request};
    }

    std::string sql = R"(insert into "Video" (name, exported_from, user_id) values (?, ?, ?, ?, ?) returning id)";

    std::vector<std::string> values;
    std::vector<std::string> keys{"name", "surname", "email", "login", "password"};
    std::string string;
    try {
        for (const auto &key: keys) {
            string = video_info.at(key).as_string();
            values.push_back(string);
        }

    } catch (const std::out_of_range &e) {
        std::cerr << "Not enough data to post:" << e.what() << std::endl;
        return {{}, http::status::bad_request};
    } catch (const std::invalid_argument &e) {
        std::cerr << "Incorrect data type" << e.what() << std::endl;
        return {{}, http::status::bad_request};
    } catch (...) {
        std::cerr << "Unexpected error with json:" << std::endl;
        return {{}, http::status::bad_request};
    }

    QSqlQuery query;
    try {
        query = QSqlQuery(db_connector_->Connect());
        query.prepare(sql.c_str());

        for (int i = 0; i < values.size(); ++i) {
            query.bindValue(i, values[i].c_str());
        }

        query = db_connector_->MakeQuery(std::move(query));
    } catch (const ConditionError &e) {
        std::cerr << "Error with request:" << e.what() << std::endl;
        return {{}, http::status::internal_server_error};
    } catch (...) {
        std::cerr << "Unexpected error with DB:" << std::endl;
        return {{}, http::status::internal_server_error};
    }

    json::object init;
    if (query.next()) {
        init["id"] = query.value("id").toString().toStdString();
    }

    for (int i = 0; i < values.size(); ++i) {
        init[keys[i]] = video_info[keys[i]];
    }

    json::value response_body(init);
    std::cout << "\t\t--- Create json value" << std::endl;

    return {response_body, http::status::ok};
}

MessageInfo UserRoute::Delete(int id) {
    return {};
}
