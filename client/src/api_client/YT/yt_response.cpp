#include "yt_response.hpp"


void YTResponse::parse_result(){
    switch(flag_){
        case 1:
            window_->MP_VK_getAlbums(result_);
            break;
        case 2:
            window_->MP_VK_getVideo(result_);
            break;
        case 3:
            window_->MP_YT_getAlbums(result_);
            break;
        case 4:
            window_->MP_YT_getVideo(result_);
            break;
    }
}
