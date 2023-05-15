//
// Created by Алексей on 02.05.2023.
//

#pragma once

#include <boost/property_tree/json_parser.hpp>
#include <boost/json.hpp>
#include <iostream>
#include <stack>

#include "namespaces.h"

namespace json = boost::json;
namespace pt = boost::property_tree;
namespace http = boost::beast::http;

struct MessageInfo {
    json::value body_;
    http::status status_;

    MessageInfo() = default;

    MessageInfo(json::value body, http::status status) :
            body_(std::move(body)),
            status_(status) {}

    friend std::ostream& operator<<(std::ostream& os, const MessageInfo& my_type);

    friend bool operator==(const MessageInfo &l, const MessageInfo &r);

};
