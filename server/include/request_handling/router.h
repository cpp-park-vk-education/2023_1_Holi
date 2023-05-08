//
// Created by Алексей on 01.05.2023.
//

#pragma once

#include <memory>
#include <vector>

#include "request_handling/i_router.h"
#include "orm/room.h"
#include "user_friend_route.h"
#include "user_route.h"
#include "video_list_route.h"
#include "video_route.h"


class Router : public IRouter {
private:
    std::unique_ptr<IRoute> route_;

public:
    Router() = default;

    explicit Router(std::unique_ptr<IRoute> route) : route_(route.release()) {}

    MessageInfo Route(const ParsedRequest &request);
};
