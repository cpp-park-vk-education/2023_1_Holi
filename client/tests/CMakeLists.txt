file(GLOB TEST_SOURCES
        ./*.cpp
        ./*/*.cpp
        ./*/*/*.cpp
        )

add_executable(client_test ${TEST_SOURCES})

target_link_libraries(client_test client_lib GTest::gtest_main GTest::gmock_main)

add_test(client_test client_test)
