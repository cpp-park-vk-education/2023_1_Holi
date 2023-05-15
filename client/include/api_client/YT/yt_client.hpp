#include "client.hpp"
#include "yt_request.hpp"
#include "yt_response.hpp"

class YTClient: public APIClient{
public:
    YTClient(std::string& access_token, int user_id): 
        APIClient(access_token, user_id) {}

    void GetPlaylists() override;
    void GetVideos() override;
};