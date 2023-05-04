add_executable(ui_test test.cpp)

target_link_libraries(ui_test vk GTest::gtest_main GTest::gmock_main)

add_test(ui_test ui_test)
