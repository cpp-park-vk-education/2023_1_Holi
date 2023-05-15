#include "client.hpp"
#include "vk_request.hpp"
#include "vk_response.hpp"

class VKClient: public APIClient{
public:
    VKClient(std::string& access_token, int user_id): 
        APIClient(access_token, user_id) {}

    void GetPlaylists() override;
    void GetVideos() override;
};