add_executable(server_test user_route_test.cpp main.cpp user_friend_route_test.cpp video_route_test.cpp video_route_test.cpp constants.h video_list_route.cpp router_test.cpp request_handler_test.cpp user_model_test.cpp message_model_test.cpp playlist_model_test.cpp video_model_test.cpp profile_reference_model_test.cpp follow_model_test.cpp chat_model_test.cpp)
target_link_libraries(server_test server_lib GTest::gtest_main)

add_test(server_test server_test)
