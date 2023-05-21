#include "response.hpp"

class YTResponse : public Response {
public:
    YTResponse(MainWindow *window, int flag){
        window_ = window;
        flag_ = flag;
    }

    void parse_result() override;
};