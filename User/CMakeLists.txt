cmake_minimum_required(VERSION 3.5)

project(user VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB PROJECT_SOURCES
        src/*.cpp
        include/*.h
        include/*.hpp
        )




include_directories(user PUBLIC include)

add_library(user_lib ${PROJECT_SOURCES})
target_include_directories(user_lib PUBLIC include)

add_subdirectory(test)

enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

