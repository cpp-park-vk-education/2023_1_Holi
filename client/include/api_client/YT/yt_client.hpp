#include "client.hpp"
#include "yt_request.hpp"
#include "yt_response.hpp"

class YTClient: public APIClient{
public:
    YTClient(std::string& access_token, int user_id, std::unique_ptr<Request> yt_request_ptr): 
        APIClient(access_token, user_id, std::move(yt_request_ptr)) {}

    void GetPlaylists() override;
};