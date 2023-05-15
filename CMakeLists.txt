cmake_minimum_required(VERSION 3.22.1)

project(hooli_share)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost 1.81.0 COMPONENTS system filesystem url REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

option(BUILD_FOR_TEST "build for test" ON)

if (BUILD_FOR_TEST)
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)
endif ()

find_package(Threads REQUIRED)

#add_subdirectory(server)
add_subdirectory(client)

