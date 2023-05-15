//
// Created by Алексей on 01.05.2023.
//

#include "request_handling/video_route.h"


MessageInfo VideoRoute::Get(int id) {
    return {};
}

MessageInfo VideoRoute::Post(json::value body) {
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

    std::string sql = R"(insert into "Video" (name, exported_from, user_id) values (?, ?, ?, ?))";

    QSqlQuery query;
    try {
        query = QSqlQuery(db_connector_->Connect());

        query.prepare(sql.c_str());
//        query.bindValue()

        query = db_connector_->MakeQuery(std::move(query));
    } catch (const ConditionError &e) {
        std::cerr << "Error with request:" << e.what() << std::endl;
        return {{}, http::status::internal_server_error};
    } catch (const std::out_of_range &e) {
        std::cerr << "Not enough data to post:" << e.what() << std::endl;
        return {{}, http::status::bad_request};
    } catch (...) {
        std::cerr << "Unexpected error with DB:" << std::endl;
        return {{}, http::status::internal_server_error};
    }


    return {};
}

MessageInfo VideoRoute::Delete(int id) {
    return {};
}