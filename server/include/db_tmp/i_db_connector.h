//
// Created by Алексей on 14.05.2023.
//

#pragma once

#include <QString>


class IDbConnectorTmp {
public:
    virtual QSqlQuery MakeQuery(QString query_string) = 0;

    virtual ~IDbConnectorTmp() = default;
};
