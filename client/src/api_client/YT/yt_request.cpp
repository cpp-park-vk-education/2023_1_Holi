#include "yt_request.hpp"
#include "yt_response.hpp"
#include <QDebug>

void YTRequest::execute(MainWindow* window, int flag){

    std::string url = "content-youtube.googleapis.com";
    std::string params = "/" + method_ + "?";

    for (auto& param : params_) {
        params += param.first + "=" + param.second + "&";
    }
    
    params += "access_token=" + access_token_;

    auto response_ptr_ = std::make_unique<YTResponse>(window, flag);

    std::cout << "PARAMS" << std::endl;
    std::cout << url << std::endl;
    std::cout << params << std::endl;

    request_maker = std::make_unique<RequestMaker>(url, params, std::move(response_ptr_));
    request_maker->Get();
}

