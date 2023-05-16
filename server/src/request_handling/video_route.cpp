//
// Created by Алексей on 01.05.2023.
//

#include "request_handling/video_route.h"


MessageInfo VideoRoute::Get(int id) {
    return {};
}

MessageInfo VideoRoute::Post(json::value body) {
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

    std::string sql = R"(insert into "Video" (name, exported_from, user_id) values (?, ?, ?) returning id)";

    std::string name;
    std::string exported_from;
    try {
        name = video_info.at("name").as_string();
        exported_from = video_info.at("exported_from").as_string();

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
        query.bindValue(0, name.c_str());
        query.bindValue(1, exported_from.c_str());
        query.bindValue(2, user_id_);

        query = db_connector_->MakeQuery(std::move(query));
    } catch (const ConditionError &e) {
        std::cerr << "Error with request:" << e.what() << std::endl;
        return {{}, http::status::internal_server_error};
    } catch (...) {
        std::cerr << "Unexpected error with DB:" << std::endl;
        return {{}, http::status::internal_server_error};
    }


    std::vector<std::string> keys{"name", "exported_from", "user_id"};
    json::object init;
    if (query.next()) {
        init["id"] = query.value("id").toString().toStdString();
    }
    init[keys[0]] = video_info[keys[0]];
    init[keys[1]] = video_info[keys[1]];
    init[keys[2]] = std::to_string(user_id_);


    json::value response_body(init);
    std::cout << "\t\t--- Create json value" << std::endl;

    return {response_body, http::status::ok};
}

MessageInfo VideoRoute::Delete(int id) {
    return {};
}