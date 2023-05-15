#include "vk_request.hpp"
#include "vk_response.hpp"

void VKRequest::execute(){

    std::string url = "https://api.vk.com/method" + method_ + "?";
    std::string params;

    for (auto& param : params_) {
        params += param.first + "=" + param.second + "&";
    }
    params += "access_token=" + access_token_ + "&v=5.131";

    request_maker_ptr.GET(response_ptr_, url, params);
}