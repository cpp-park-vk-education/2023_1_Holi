project(hooli_share)
cmake_minimum_required(VERSION 3.5)

#<<<<<<< HEAD
#project(api_client VERSION 0.1 LANGUAGES CXX)
#
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#
#file(GLOB PROJECT_SOURCES
#        api_client/src
#        api_client/src/VK/*.cpp
#        api_client/src/YT/*.cpp
#        api_client/headers/Base/*.hpp
#        api_client/headers/VK/*.hpp
#        api_client/headers/YT/*.hpp
#    )
#
#include_directories(api_client PUBLIC api_client/headers/VK api_client/headers/YT api_client/headers/Base)
#include_directories(/usr/local/include)
#link_directories(/usr/local/include/jsoncpp/1.9.5/lib)
#
#add_library(api_client_lib ${PROJECT_SOURCES})
#target_include_directories(api_client_lib PUBLIC api_client/headers/VK api_client/headers/YT api_client/headers/Base)
#
#add_subdirectory(api_client/tests)
#=======

find_package(Boost 1.81.0 COMPONENTS system filesystem url REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

option(BUILD_FOR_TEST "build for test" ON)

if (BUILD_FOR_TEST)
    enable_testing()
    find_package(GTest REQUIRED)
    include(GoogleTest)
endif ()

find_package(Threads REQUIRED)

add_subdirectory(server)
add_subdirectory(client)
