cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(yt)

add_library(yt STATIC yt_client.cpp yt_request.cpp yt_response.cpp)

target_include_directories(yt PUBLIC headers/Base headers/YT)




