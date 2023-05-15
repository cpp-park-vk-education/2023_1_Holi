#include "response.hpp"

class VKResponse: public Response{
public:
    VKResponse(){}
    
    void parse_result() override;
};