#include "response.hpp"

class YTResponse: public Response{
public:
    YTResponse(){}

    void parse_result() override;
};