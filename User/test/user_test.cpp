#include "user.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class IResponseMaker {
public:
    virtual int makeResponse(User& user) {
        return 0;
    };
};

class MockResponseMaker : public IResponseMaker {
public:
    MOCK_METHOD1(makeResponse, int(User&));
};

TEST(UserTest, DefaultConstructor) {
  User user;
  EXPECT_EQ(0, user.getId());
  EXPECT_EQ("", user.getName());
  EXPECT_EQ("", user.getSurname());
  EXPECT_EQ("", user.getEmail());
  EXPECT_EQ("", user.getAvatar());
}

TEST(UserTest, ConstructorWithParameters) {
  User user(1, "John", "Doe", "johndoe@example.com", "https://example.com/avatar.jpg");
  EXPECT_EQ(1, user.getId());
  EXPECT_EQ("John", user.getName());
  EXPECT_EQ("Doe", user.getSurname());
  EXPECT_EQ("johndoe@example.com", user.getEmail());
  EXPECT_EQ("https://example.com/avatar.jpg", user.getAvatar());
}

TEST(UserTest, SettersAndGetters) {
  User user;
  user.setId(2);
  user.setName("Jane");
  user.setSurname("Doe");
  user.setEmail("janedoe@example.com");
  user.setAvatar("https://example.com/avatar2.jpg");
  user.setAccessToken("token");
  user.setRefreshToken("refresh_token");
  user.setExpiresIn(3600);

  EXPECT_EQ(2, user.getId());
  EXPECT_EQ("Jane", user.getName());
  EXPECT_EQ("Doe", user.getSurname());
  EXPECT_EQ("janedoe@example.com", user.getEmail());
  EXPECT_EQ("https://example.com/avatar2.jpg", user.getAvatar());
  EXPECT_EQ("token", user.getAccessToken());
  EXPECT_EQ("refresh_token", user.getRefreshToken());
  EXPECT_EQ(3600, user.getExpiresIn());
}

TEST(UserTest, SetFriend) {
  User user;
  user.setFriend(1);
  user.setFriend(2);
  user.setFriend(3);
  user.setFriend(1);

  EXPECT_EQ(3, user.friends_id.size());
  EXPECT_EQ(true, user.isFriend(1));
  EXPECT_EQ(false, user.isFriend(4));
}

TEST(UserTest, SetFriendTest) {
    MockResponseMaker responseMaker;
    User user;
    user.setFriend(1);
    EXPECT_FALSE(user.isFriend(2));
    EXPECT_TRUE(user.isFriend(1));
    EXPECT_CALL(responseMaker, makeResponse(testing::Ref(user)))
        .WillOnce(testing::Return(0));
    int response = responseMaker.makeResponse(user);
    EXPECT_EQ(response, 0);
}
