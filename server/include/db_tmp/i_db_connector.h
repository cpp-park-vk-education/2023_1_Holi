//
// Created by Алексей on 14.05.2023.
//

#pragma once

#include <QString>


class IDbConnectorTmp {
public:
    virtual QSqlQuery MakeQuery(QSqlQuery &&query) = 0;

    virtual QSqlDatabase Connect() = 0;

    virtual void Disconnect() = 0;

    virtual ~IDbConnectorTmp() = default;
};
