//
// Created by Алексей on 04.05.2023.
//

#pragma once

#include <utility>
#include <QDateTime>

#include "i_db_model.h"


class Message : IDbModel {
private:
    int id_;

    QString text_;
    QDateTime sent_at_;
    int user_id_;
    int chat_id_;

    std::unique_ptr<IDbConnector> connector_;

public:
    Message() = default;

    Message(
            QString text,
            QDateTime sent_at,
            int user_id,
            int chat_id
    ) :
            text_(std::move(text)),
            sent_at_(std::move(sent_at)),
            user_id_(user_id),
            chat_id_(chat_id) {}

    explicit Message(int id, std::unique_ptr<IDbConnector> connector) : id_(id), connector_(connector.release()) {}

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
