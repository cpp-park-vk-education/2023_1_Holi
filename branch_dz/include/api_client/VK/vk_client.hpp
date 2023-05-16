#include "client.hpp"
#include "vk_request.hpp"
#include "vk_response.hpp"

#include <memory>
#include "functional"

class VKClient: public APIClient{
public:
    VKClient(std::string& access_token, int user_id): 
        APIClient(access_token, user_id) {}

    ~VKClient() override {
        std::cerr << "VKClient destruct" << std::endl;
    }

    void GetPlaylists(MainWindow* window, int flag) override;
    void GetVideos(MainWindow* window, int flag) override;

private:
    std::unique_ptr<VKRequest> vk_request;
};
