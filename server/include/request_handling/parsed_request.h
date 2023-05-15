//
// Created by Алексей on 03.05.2023.
//

#pragma once

#include <utility>

#include "namespaces.h"

struct ParsedRequest {
    url::params_view parameters_;
    std::string path_;
    http::verb method_;
    json::value body_;

    ParsedRequest() = default;

    ParsedRequest(
            const url::params_view &parameters,
            std::string path,
            http::verb method,
            json::value body = {}
    );
};
