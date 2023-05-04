//
// Created by Алексей on 01.05.2023.
//

#pragma once

#include "router.h"

class Session;


class Room {
public:
    void Join(std::weak_ptr<Session> session);

    void Deliver(json::value &message);

    void Leave(std::weak_ptr<Session> session);
};
