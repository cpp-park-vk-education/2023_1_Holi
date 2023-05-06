#include "yt_client.hpp"
#include "request.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;


class GMockYTRequest : public Request {
public:
    MOCK_METHOD(void, execute, (), (override));
};


TEST(YTClientTest, GmockTestRequestExecuteCall) {
    std::string access_token = "123";
    int user_id = 123;

    auto request = std::make_unique<GMockYTRequest>();

    GMockYTRequest* mock_ptr = request.get();

    YTClient client(access_token, user_id, std::move(request));
    

    EXPECT_CALL(*mock_ptr, execute());
    try{
      client.GetPlaylists();
    } catch(...) {}
}