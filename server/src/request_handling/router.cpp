//
// Created by Алексей on 01.05.2023.
//

#include "request_handling/router.h"

//
//ResultCode Router::GetParameter(std::string key, int &value) {
//    auto parameter = request_.parameters_.find(key);
//    if (parameter == request_.parameters_.end()) {
//        std::cerr << "Error: improper url parameters" << std::endl;
//        return bad_request;
//    }
//
//    try {
//        value = std::stoi((*parameter).value);
//    } catch (std::invalid_argument const &ex) {
//        std::cerr << "Error: invalid url parameters" << std::endl;
//        return bad_request;
//    } catch (...) {
//        std::cerr << "Unexpected error with parameters" << std::endl;
//        return bad_request;
//    }
//
//    if (value <= 0) {
//        std::cerr << "Error: Negative user id" << std::endl;
//        return not_found;
//    }
//
//    return success;
//}


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

    request_ = request;

    if (request_.path_.empty()) {
        std::cerr << "Error: empty path" << std::endl;
        return {{}, http::status::bad_request};
    }
    if (request_.parameters_.empty()) {
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
        user_id = std::stoi((*parameter).value);
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
    if (request_.path_ == "/user") {
        route = std::make_unique<UserRoute>(user_id);
    }


    parameter = request.parameters_.find("resource_id");
    if (parameter == request.parameters_.end() && !route && request.method_ != http::verb::post) {
        std::cerr << "Error: improper url parameters" << std::endl;
        return {{}, http::status::bad_request};
    }
    int resource_id = 0;
    if (route) {
        resource_id = user_id;
    } else {
        try {
            user_id = std::stoi((*parameter).value);
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
    }


    if (request_.path_ == "/video") {
        route = std::make_unique<VideoListRoute>(user_id);
    }

    if (!route) {
        std::cerr << "Error: Improper path" << std::endl;
        return {{}, http::status::not_found};
    }

    // todo json check

    switch (request_.method_) {
        case (http::verb::get): {
            return route->Get(resource_id);
        }
        case (http::verb::post): {
            return route->Post(request.body_);
        }
        case (http::verb::delete_): {

            break;
        }
        default: {

        }
    }

    return {{}, http::status::not_found};
}

