//
// Created by Алексей on 01.05.2023.
//

#pragma once

#include <memory>
#include <vector>
#include <string>

#include "request_handling/i_router.h"
#include "orm/room.h"
#include "user_friend_route.h"
#include "user_route.h"
#include "video_list_route.h"
#include "video_route.h"
#include "video_all_route.h"
#include "video_list_all_route.h"
#include "user_auth_check_route.h"
#include "user_auth_login_route.h"

enum ErrorCode {
    error,
    success
};

struct ErrorMessage {
    ErrorCode code;
    std::string message;
};


class Router : public IRouter {
private:
    std::unique_ptr<IRoute> route_;
    ParsedRequest request_;

public:
    Router() = default;

    explicit Router(std::unique_ptr<IRoute> route) : route_(route.release()) {}

    MessageInfo Route(const ParsedRequest &request);

private:
    ErrorMessage GetParam(const std::string &param, url::params_base::iterator &iter);

    ErrorMessage ToIntWithCheck(const url::params_base::iterator &iterm, int &param);
};
