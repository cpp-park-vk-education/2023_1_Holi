//
// Created by Алексей on 03.05.2023.
//

#include <boost/url/src.hpp>

#include "request_handling/parsed_request.h"


ParsedRequest::ParsedRequest(
        const urls::params_encoded_view &parameters,
        std::string path,
        http::verb method,
        json::value body
) :
        parameters_(parameters),
        path_(std::move(path)),
        method_(method),
        body_(std::move(body)) {}
