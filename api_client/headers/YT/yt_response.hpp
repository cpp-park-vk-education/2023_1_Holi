#include "response.hpp"

class YTResponse: public Response{
public:
    YTResponse(){}
    //YTResponse(bool success, int error_code, Json::Value result): 
    //    Response(success, error_code, result) {}

    YTResponse(bool success, int error_code): 
        Response(success, error_code){}

    void parse_result() override;
};