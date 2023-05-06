#include "client.hpp"
#include "vk_request.hpp"
#include "vk_response.hpp"

class VKClient: public APIClient{
public:
    VKClient(std::string& access_token, int user_id, std::unique_ptr<Request> request_ptr): 
        APIClient(access_token, user_id, std::move(request_ptr)) {}

    void GetPlaylists() override;
};