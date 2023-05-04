//
// Created by Алексей on 04.05.2023.
//

#pragma once

#include <QDateTime>

#include "i_db_model.h"


class Chat : IDbModel {
private:
    int id_;

    QString name_;
    QString image_;
    QDateTime created_at_;
    std::vector<int> users_;
    std::vector<int> messages_;

    std::unique_ptr<IDbConnector> connector_;

public:
    Chat() = default;

    Chat(
            QString name,
            QString image,
            QDateTime created_at,
            std::vector<int> users = {},
            std::vector<int> messages = {}
    )
            :
            name_(std::move(name)),
            image_(std::move(image)),
            created_at_(std::move(created_at)),
            users_(std::move(users)),
            messages_(std::move(messages)) {}

    explicit Chat(int id, std::unique_ptr<IDbConnector> connector) : id_(id), connector_(connector.release()) {}

    void SetConnector(std::unique_ptr<IDbConnector> connector) override {
        std::exchange(connector_, std::move(connector));
    };

    bool Save() override;

    bool Alter(int id) override;

    json::value SelectAll() override;

    json::value Get(int id) override;

    bool Delete(int id) override;

    json::value SelectWith(QString condition) override;

    bool DeleteWith(QString condition) override;

};
