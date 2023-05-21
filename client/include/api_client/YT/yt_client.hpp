#include "client.hpp"
#include "vk_request.hpp"
#include "vk_response.hpp"

#include <memory>
#include "functional"

class YTClient: public APIClient{
public:
    YTClient(std::string& access_token, int user_id): 
        APIClient(access_token, user_id) {}

    ~YTClient() override {
        std::cerr << "VKClient destruct" << std::endl;
    }

    void GetPlaylists(MainWindow* window, int flag) override;
    void GetVideos(MainWindow* window, int flag) override;

private:
    std::unique_ptr<YTRequest> vk_request;
};
