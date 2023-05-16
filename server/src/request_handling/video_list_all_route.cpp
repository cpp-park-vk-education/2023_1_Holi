//
// Created by Алексей on 16.05.2023.
//

#include "request_handling/video_list_all_route.h"


MessageInfo VideoListAllRoute::Get(int id) {
    if (id <= 0) {
        std::cerr << "Non-positive id" << std::endl;
        return {{}, http::status::not_found};
    }

    std::string sql = R"(select * from "Playlist" where user_id = )" + std::to_string(id);

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

    std::vector<std::string> keys{"id", "name", "exported_from", "user_id"};
    json::object table_row;
    json::array rows;
    while (query.next()) {
        for (const auto &i: keys) {
            table_row[i] = query.value(i.c_str()).toString().toStdString();
        }

        rows.push_back(table_row);
        table_row.clear();
    }

    json::value body(rows);
    std::cout << "\t\t--- Create json value" << std::endl;

    return {body, http::status::ok};
}

MessageInfo VideoListAllRoute::Post(json::value body) {
    return {};
}

MessageInfo VideoListAllRoute::Delete(int id) {
    return {};
}
