//
// Created by Алексей on 04.05.2023.
//

#pragma once

#include "i_db_connector.h"


class DbConnector : public IDbConnector {
public:
    std::vector<std::map<std::string, std::string>> Connect(QString sql_string, QString table_name) override;

private:
    int user_id;
};
