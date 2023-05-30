#include "client.hpp"
#include "yt_request.hpp"
#include "yt_response.hpp"

#include <memory>
#include "functional"

class YTClient: public APIClient{
public:
    YTClient(std::string& access_token): 
        APIClient(access_token) {}

    ~YTClient() override {
        std::cerr << "YTClient destruct" << std::endl;
    }

    void GetPlaylists(MainWindow* window, int flag) override;
    void GetVideos(MainWindow* window, int flag, std::string  PlaylistID) override;

private:
    std::unique_ptr<YTRequest> yt_request;
};
