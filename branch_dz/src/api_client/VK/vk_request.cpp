#include "vk_request.hpp"
#include "vk_response.hpp"
#include <QDebug>

void VKRequest::execute(MainWindow* window, int flag){

    std::string url = "api.vk.com";
    std::string params = "/method/" + method_ + "?";

    for (auto& param : params_) {
        params += param.first + "=" + param.second + "&";
    }
    
    params += "access_token=" + access_token_ + "&v=5.131";

    auto response_ptr_ = std::make_unique<VKResponse>(window, flag);

    request_maker = std::make_unique<RequestMaker>(url, params, std::move(response_ptr_));
    request_maker->Get();
//    std::cout << "TEST" << std::endl;
//    qDebug() << "TEST";
}

