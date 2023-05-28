#include "api_client/VK/vk_client.hpp"
#include "api_client/VK/vk_request.hpp"

void VKClient::GetPlaylists(MainWindow* window, int flag){
    std::string method = "video.getAlbums";
    std::map<std::string, std::string> params = 
    {
        {"owner_id", std::to_string(user_id_)},
        {"extended", std::to_string(0)}
    };
    vk_request = std::make_unique<VKRequest>();

    vk_request->setAccessToken(access_token_);
    vk_request->setMethod(method);
    vk_request->setParams(params);

    vk_request->execute(window, flag);
}


void VKClient::GetVideos(MainWindow* window, int flag, std::string playlistId){
    std::string method = "video.get";
    std::map<std::string, std::string> params = 
    {
        {"owner_id", std::to_string(user_id_)},
        {"extended", std::to_string(0)}
    };
    vk_request = std::make_unique<VKRequest>();

    vk_request->setAccessToken(access_token_);
    vk_request->setMethod(method);
    vk_request->setParams(params);

    vk_request->execute(window, flag);
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
