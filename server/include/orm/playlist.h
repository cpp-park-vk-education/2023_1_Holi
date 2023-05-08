//
// Created by Алексей on 04.05.2023.
//

#pragma once

#include "orm/i_db_model.h"


class Playlist : IDbModel {
private:
    int id_;

    QString name_;
    QString image_;
    QString exported_from_;
    int user_;
    std::vector<int> videos_;

    std::unique_ptr<IDbConnector> connector_;

public:
    Playlist() = default;
    Playlist(
            QString name,
            QString image,
            QString exported_from,
            int user,
            std::vector<int> videos = {}
    )
            :
            name_(std::move(name)),
            image_(std::move(image)),
            exported_from_(std::move(exported_from)),
            user_(user),
            videos_(std::move(videos)) {}

    explicit Playlist(int id, std::unique_ptr<IDbConnector> connector) : id_(id), connector_(connector.release()) {}

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
