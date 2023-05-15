#include "response.hpp"

//constexpr std::map<>

class VKResponse: public Response{
public:
    VKResponse(){}
    
    void parse_result() override;
};