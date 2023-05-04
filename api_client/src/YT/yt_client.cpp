#include "yt_client.hpp"
#include "yt_request.hpp"

void YTClient::GetPlaylists(){
    std::string method = "method";
    std::map<std::string, std::string> params = {};

    request_ptr_->setAccessToken(access_token_);
    request_ptr_->setMethod(method);
    request_ptr_->setParams(params);

    request_ptr_->execute();
}