#include "response.hpp"
//constexpr std::map<>


class VKResponse : public Response {
public:
    VKResponse(MainWindow *window, int flag) : Response(window, flag) {}

    void parse_result() override;
};