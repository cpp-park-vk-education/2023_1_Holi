//
// Created by Алексей on 14.05.2023.
//

#include "db_tmp/db_connector.h"


QSqlQuery DbConnectorTmp::MakeQuery(QSqlQuery &&query) {
    if (!query.exec()) {
        throw ConditionError(query.lastError().text().toStdString());
    }

    if (!query.isActive()) {
        throw ConditionError("Cant make request");
    }

    std::cout << "\t\t--- Query executed successfully" << std::endl;
    std::cout << "\t\t--- Amount of rows read: " << query.size() << std::endl;

    return query;
}

QSqlDatabase DbConnectorTmp::Connect() {
    if (connection_.isOpen()) {
        std::cout << "\t\t--- Connect to db" << std::endl;
        return connection_;
    }

    connection_ = QSqlDatabase::addDatabase("QPSQL");
    connection_.setDatabaseName(db_name_);
    connection_.setHostName("localhost");
    connection_.setUserName("postgres");
    connection_.setPassword("11022003ks");

    bool is_open = connection_.open();

    if (!is_open) {
        throw DbConnectError("Cant connect to db");
    }

    std::cout << "\t\t--- Connect to db" << std::endl;
    return connection_;
}


DbConnectorTmp::~DbConnectorTmp() {
    DbConnectorTmp::Disconnect();
}

void DbConnectorTmp::Disconnect() {
    if (connection_.isOpen()) {
        connection_.close();
        std::cout << "\t\t--- Disconnect from db" << std::endl;
    }
}
