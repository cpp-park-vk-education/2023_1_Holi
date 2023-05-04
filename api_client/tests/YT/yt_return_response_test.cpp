#include "yt_response.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class IResponseGetter {
public:
    virtual void get_response(std::string& response) = 0;
};


class GMockResponseGetter : public IResponseGetter {
public:
    MOCK_METHOD(void, get_response, (std::string& response), (override));
};


TEST(YTResponsetTest, TestReturnResponsToGUI) {
    auto getter = std::make_unique<GMockResponseGetter>();

    YTResponse response(true, 123);
    std::string result("result");

    EXPECT_CALL(*getter, get_response(result));
    try{
      response.parse_result();
    } catch(...) {}
}