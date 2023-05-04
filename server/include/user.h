//
// Created by Алексей on 04.05.2023.
//

#pragma once

#include "i_db_model.h"


class User : IDbModel {
private:
    int id_;

    QString name_;
    QString surname_;
    QString email_;
    QString avatar_;
    QString login_;
    QString password_;
    std::vector<int> chats_;
    std::vector<int> videos_;

    std::unique_ptr<IDbConnector> connector_;

public:
    User() = default;

    User(
            QString name,
            QString surname,
            QString email,
            QString avatar,
            QString login,
            QString password,
            std::vector<int> chats = {},
            std::vector<int> videos = {}
    ) :
            name_(std::move(name)),
            surname_(std::move(surname)),
            email_(std::move(email)),
            avatar_(std::move(avatar)),
            login_(std::move(login)),
            password_(std::move(password)),
            chats_(std::move(chats)),
            videos_(std::move(videos)) {}

    explicit User(int id, std::unique_ptr<IDbConnector> connector) : id_(id), connector_(connector.release()) {}

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
