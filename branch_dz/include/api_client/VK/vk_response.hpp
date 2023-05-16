#include "response.hpp"

class VKResponse : public Response {
public:
    VKResponse(MainWindow *window, int flag){
        window_ = window;
        flag_ = flag;
    }

    void parse_result() override;
};