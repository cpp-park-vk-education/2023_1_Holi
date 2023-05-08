//
// Created by Алексей on 03.05.2023.
//

#pragma once

#include <utility>

#include "namespaces.h"

struct ParsedRequest {
    urls::params_encoded_view parameters_;
    std::string path_;
    http::verb method_;
    json::value body_;

    ParsedRequest(
            const boost::urls::params_encoded_view &parameters,
            std::string path,
            http::verb method,
            json::value body = {}
    );
};
