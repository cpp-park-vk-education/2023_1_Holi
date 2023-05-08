//
// Created by Алексей on 04.05.2023.
//

#pragma once

#include "orm/i_db_model.h"


class ProfileReference : IDbModel {
private:
    int id_;

    QString reference_;
    QString service_;
    int user_;

    std::unique_ptr<IDbConnector> connector_;

public:
    ProfileReference() = default;

    ProfileReference(
            QString reference,
            QString service,
            int user
    )
            :
            reference_(std::move(reference)),
            service_(std::move(service)),
            user_(user) {}

    explicit ProfileReference(int id, std::unique_ptr<IDbConnector> connector) : id_(id),
                                                                                 connector_(connector.release()) {}

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
