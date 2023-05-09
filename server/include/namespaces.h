//
// Created by Алексей on 01.05.2023.
//

#pragma once

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/beast/http.hpp>
#include <boost/json.hpp>
#include <boost/url.hpp>


namespace net = boost::asio;
namespace beast = boost::beast;
namespace json = boost::json;
namespace urls = boost::urls;

namespace http = beast::http;
namespace websocket = beast::websocket;

using tcp = boost::asio::ip::tcp;
