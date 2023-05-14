//
// Created by Алексей on 01.05.2023.
//

#include "request_handling/router.h"


MessageInfo Router::Route(const ParsedRequest &request) {
//    return {json::parse(R"(
//                {
//                    "name": "name",
//                    "image": "image",
//                    "exported_from": "exported_from",
//                    "user": "6",
//                    "playlists": ["12", "2", "43"]
//                }
//            )"), http::status::ok};

    if (request.path_.empty()) {
        std::cerr << "Error: empty path" << std::endl;
        return {{}, http::status::bad_request};
    }

    if (request.parameters_.empty()) {
        std::cerr << "Error: empty url parameters" << std::endl;
        return {{}, http::status::bad_request};
    }

    auto parameter = request.parameters_.find("user_id");
    if (parameter == request.parameters_.end()) {
        std::cerr << "Error: improper url parameters" << std::endl;
        return {{}, http::status::bad_request};
    }

    int user_id = 0;
    try {
        user_id = std::stol((*parameter).value);
    } catch (std::invalid_argument const &ex) {
        std::cerr << "Error: invalid url parameters" << std::endl;
        return {{}, http::status::bad_request};
    } catch (...) {
        std::cerr << "Unexpected error with parameters" << std::endl;
        return {{}, http::status::bad_request};
    }

    if (user_id <= 0) {
        std::cerr << "Error: Negative user id" << std::endl;
        return {{}, http::status::not_found};
    }

    std::unique_ptr<IRoute> route;
    if (request.path_ == "/user") {
        route = std::make_unique<UserRoute>(user_id);
    }

    if (!route) {
        std::cerr << "Error: Improper path" << std::endl;
        return {{}, http::status::not_found};
    }

    switch (request.method_) {
        case (http::verb::get): {
            route->Get();
            break;
        }
        case (http::verb::post): {

            break;
        }
        case (http::verb::delete_): {

            break;
        }
        default: {

        }
    }
    return {{}, http::status::not_found};
}

