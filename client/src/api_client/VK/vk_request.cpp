#include "vk_request.hpp"
#include "vk_response.hpp"

void VKRequest::execute(){

    std::string url = "api.vk.com";
    std::string params = "/method/" + method_ + "?";

    for (auto& param : params_) {
        params += param.first + "=" + param.second + "&";
    }
    params += "access_token=" + access_token_ + "&v=5.131";

    auto response_ptr_ = std::make_unique<VKResponse>();

    auto request_maker_ptr_ = std::make_unique<RequestMaker>(url, params, std::move(response_ptr_));
    request_maker_ptr_->GET();
}