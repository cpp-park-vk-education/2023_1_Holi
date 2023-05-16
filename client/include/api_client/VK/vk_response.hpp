#include "response.hpp"
#include "gui/mainwindow.h"
//constexpr std::map<>


class VKResponse: public Response{
public:
    VKResponse(MainWindow* window): window_(window) {}
    
    void parse_result() override;
};