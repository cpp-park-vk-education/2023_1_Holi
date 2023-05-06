#include "response.hpp"

class VKResponse: public Response{
public:
    VKResponse(){}
    //VKResponse(bool success, int error_code, Json::Value result): 
    //    Response(success, error_code, result){}
    VKResponse(bool success, int error_code): 
        Response(success, error_code){}
    //todo: указ. на requestMaker

    void parse_result() override;
};