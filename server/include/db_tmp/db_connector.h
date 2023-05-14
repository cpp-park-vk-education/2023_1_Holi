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


enum ConnectReturnCode {
    success,
    already_connected,
    error
};


class DbConnector : public IDbConnector {
public:
    explicit DbConnector(QString db_name = "hooli_share") : db_name_(std::move(db_name)) {}

    QSqlQuery MakeQuery(QString query_string) override;

    ~DbConnector();

private:
    QSqlDatabase connection_;
    const QString db_name_;

private:
    void Connect();

    void Disconnect();
};

