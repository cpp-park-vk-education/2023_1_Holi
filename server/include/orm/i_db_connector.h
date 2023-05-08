//
// Created by Алексей on 04.05.2023.
//

#pragma once

#include <map>
#include <QString>
#include <vector>

#include "namespaces.h"


class IDbConnector {
public:
    virtual std::vector<std::map<std::string, std::string>> Connect(QString sql_string, QString table_name) = 0;

    virtual ~IDbConnector() = default;
};
