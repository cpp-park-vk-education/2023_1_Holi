add_executable(server_test
        main.cpp
        constants.h
        request_handling/router_test.cpp
        request_handling/request_handler_test.cpp)

target_link_libraries(server_test server_lib GTest::gtest_main)

add_test(server_test server_test)
