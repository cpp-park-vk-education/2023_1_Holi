//
// Created by Алексей on 02.05.2023.
//

#pragma once

#include <memory>
#include <QString>

#include "i_db_connector.h"
#include "namespaces.h"


class IDbModel {
public:
    virtual bool Save() = 0;

    virtual bool Alter(int id) = 0;

    virtual json::value SelectAll() = 0;

    virtual json::value Get(int id) = 0;

    virtual bool Delete(int id) = 0;

    virtual json::value SelectWith(QString condition) = 0;

    virtual bool DeleteWith(QString condition) = 0;

    virtual void SetConnector(std::unique_ptr<IDbConnector> connector) = 0;

    virtual ~IDbModel() = default;
};
