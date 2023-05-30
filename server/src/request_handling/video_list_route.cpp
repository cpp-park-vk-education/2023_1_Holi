//
// Created by Алексей on 01.05.2023.
//

#include "request_handling/video_list_route.h"


MessageInfo VideoListRoute::Get(int id) {
    return {};
}

MessageInfo VideoListRoute::Post(json::value body) {
    if (user_id_ <= 0) {
        std::cerr << "Non-positive id" << std::endl;
        return {{}, http::status::not_found};
    }

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

    std::string sql = R"(insert into "Playlist" (name, exported_from, user_id, id_in_service, description) values (?, ?, ?, ?, ?) returning id)";

    std::map<std::string, std::string> cols;
    int id_in_service;
    try {
        cols["name"] = video_info.at("name").as_string();
        cols["exported_from"] = video_info.at("exported_from").as_string();
        cols["id_in_service"] = video_info.at("id_in_service").as_string();
        cols["description"] = video_info.at("description").as_string();

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
        query.bindValue(0, cols["name"].c_str());
        query.bindValue(1, cols["exported_from"].c_str());
        query.bindValue(2, user_id_);
        query.bindValue(3, cols["id_in_service"].c_str());
        query.bindValue(4, cols["description"].c_str());

//        query.bindValue(2, user_id_);
//        for (int i = 0; const auto &col: cols) {
//            if (i == 2) { ++i; }
//            query.bindValue(i++, col.second.c_str());
//        }

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
    init["user_id"] = std::to_string(user_id_);
    for (const auto &col: cols) {
        init[col.first] = video_info[col.first];
    }

    json::value response_body(init);
    std::cout << "\t\t--- Create json value" << std::endl;

    return {response_body, http::status::ok};
}

MessageInfo VideoListRoute::Delete(int id) {
    return {};
}
