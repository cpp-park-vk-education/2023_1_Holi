find_package(GTest REQUIRED)

file(GLOB TEST_SOURCES
        VK/*.cpp
        YT/*.cpp
    )

add_executable(api_client_test ${TEST_SOURCES})
target_link_libraries(api_client_test api_client_lib GTest::GTest GTest::gtest_main GTest::gmock_main)

add_test(api_client_test api_client_test)