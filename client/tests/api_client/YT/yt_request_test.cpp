#include "yt_request.hpp"
#include "yt_response.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class IRequestMaker {
public:
    virtual void get(std::string& url) = 0;
};


class GMockRequestMaker : public IRequestMaker {
public:
    MOCK_METHOD(void, get, (std::string& url), (override));
};


TEST(YTRequestTest, GmockTestRequestMakerCall) {
    auto requestMaker = std::make_unique<GMockRequestMaker>();

    std::string token = "123";
    std::string method = "get_video";
    std::map<std::string, std::string> params;

    auto response_ptr = std::make_unique<YTResponse>();
    YTRequest request(std::move(response_ptr)); //Добавить к аргументам requestMaker

    std::string url("test url");

    EXPECT_CALL(*requestMaker, get(url));
    try{
      request.execute();
    } catch(...) {}
}