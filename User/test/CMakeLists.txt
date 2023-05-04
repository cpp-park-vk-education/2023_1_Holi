find_package(GTest REQUIRED)

add_executable( user_test main.cpp user_test.cpp )

target_link_libraries(user_test user_lib GTest::gtest_main GTest::gmock_main)

add_test(user_test  user_test )