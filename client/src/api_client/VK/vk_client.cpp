#include "vk_client.hpp"
#include "vk_request.hpp"

void VKClient::GetPlaylists(){
    std::string method = "method";
    std::map<std::string, std::string> params = {};

    request_ptr_->setAccessToken(access_token_);
    request_ptr_->setMethod(method);
    request_ptr_->setParams(params);

    request_ptr_->execute();
}


/* Response:
{
    "response":{
        "count":1
            "items":[
                0:{
                    "id":1
                    "owner_id":319426307
                    "title":"test_api"
                    "response_type":"min"
                }
            ]
    }
}
*/