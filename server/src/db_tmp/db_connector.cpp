//
// Created by Алексей on 14.05.2023.
//

#include "db_tmp/db_connector.h"


QSqlQuery DbConnector::MakeQuery(QString query_string) {
    Connect();

    QSqlQuery query(connection_);

    if (!query.exec(query_string)) {
        throw ConditionError(query.lastError().text().toStdString());
    }

    if (!query.isActive()) {
        throw ConditionError("Cant make request");
    }

    std::cout << "Query executed successfully" << std::endl;
    std::cout << "Amount of rows read: " << query.size() << std::endl;

//    int i = 0;
//    while (query.next()) {
//        ui->twOrg->setItem(i, 0, new
//                QTableWidgetItem(query.value("customer_id").toString()));
//        ui->twOrg->setItem(i, 1, new
//                QTableWidgetItem(query.value("company_name").toString()));
//        ui->twOrg->setItem(i, 2, new
//                QTableWidgetItem(query.value("last_name").toString()));
//        ui->twOrg->setItem(i, 3, new
//                QTableWidgetItem(query.value("first_name").toString()));
//        ui->twOrg->setItem(i, 4, new
//                QTableWidgetItem(query.value("address").toString()));
//        ui->twOrg->setItem(i, 5, new
//                QTableWidgetItem(query.value("index").toString()));
//        ui->twOrg->setItem(i, 6, new
//                QTableWidgetItem(query.value("phone").toString()));
//        i++;
//    }

    Disconnect();

    return query;
}

void DbConnector::Connect() {
    if (connection_.isOpen()) {
//        return already_connected;
        return;
    }

    connection_ = QSqlDatabase::addDatabase("QPSQL");
    connection_.setDatabaseName(db_name_);
    connection_.setHostName("localhost");
    connection_.setUserName("aleksej");
    connection_.setPassword("postgres");

//    return (connection_.open() ? success : error);
}


DbConnector::~DbConnector() {
    Disconnect();
}

void DbConnector::Disconnect() {
    if (connection_.isOpen()) {
        connection_.close();
    }
}
