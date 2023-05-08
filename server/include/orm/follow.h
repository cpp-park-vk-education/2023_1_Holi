//
// Created by Алексей on 04.05.2023.
//

#pragma once

#include <QDateTime>

#include "i_db_model.h"


class Follow : IDbModel {
private:
    int id_;

    QDateTime created_at_;
    int first_user_;
    int second_user_;

    std::unique_ptr<IDbConnector> connector_;

public:
    Follow() = default;

    Follow(
            QDateTime created_at,
            int first_user,
            int second_user
    )
            :
            created_at_(std::move(created_at)),
            first_user_(first_user),
            second_user_(second_user) {}

    explicit Follow(int id, std::unique_ptr<IDbConnector> connector) : id_(id), connector_(connector.release()) {}

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
