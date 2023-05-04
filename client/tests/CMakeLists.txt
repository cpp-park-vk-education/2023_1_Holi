add_executable(client_test response_handler_test.cpp main.cpp)
target_link_libraries(client_test client_lib GTest::gtest_main)

add_test(client_test client_test)
