#include "vk_response.hpp"


void VKResponse::parse_result(){
    std::cout << "RESULT" << std::endl;
    std::cout << result_ << std::endl;

    window_->MP_VK_getAlbums(result_);
    //вызов метода gui
}
