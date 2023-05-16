//
// Created by Алексей on 14.05.2023.
//

#pragma once

#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "i_db_connector.h"
#include "orm/errors.h"


//enum ConnectReturnCode {
//    success,
//    already_connected,
//    error
//};


class DbConnectorTmp : public IDbConnectorTmp {
public:
    explicit DbConnectorTmp(QString db_name = "hooli_share") : db_name_(std::move(db_name)) {}

    QSqlQuery MakeQuery(QSqlQuery &&query) override;

    QSqlDatabase Connect() override;

    void Disconnect() override;

    ~DbConnectorTmp();

private:
    QSqlDatabase connection_;
    const QString db_name_;
};

