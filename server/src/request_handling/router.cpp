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
    // todo убрать комменты и мб разбить на функции

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
        std::cerr << "Error: Non-positive user id" << std::endl;
        return {{}, http::status::not_found};
    }

    int resource_id = 0;
    parameter = request.parameters_.find("resource_id");
    if (parameter == request.parameters_.end()) {
        resource_id = user_id;
    } else {
        try {
            resource_id = std::stoi((*parameter).value);
        } catch (std::invalid_argument const &ex) {
            std::cerr << "Error: invalid url parameters" << std::endl;
            return {{}, http::status::bad_request};
        } catch (...) {
            std::cerr << "Unexpected error with parameters" << std::endl;
            return {{}, http::status::bad_request};
        }
    }
    if (resource_id <= 0) {
        std::cerr << "Error: Non-positive resource id" << std::endl;
        return {{}, http::status::not_found};
    }


    std::unique_ptr<IRoute> route;
    if (request_.path_ == "/user") {
        route = std::make_unique<UserRoute>(user_id);
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
            return route->Delete(resource_id);
        }
        default: {

        }
    }

    return {{}, http::status::not_found};
}

