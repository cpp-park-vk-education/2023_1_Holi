cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(vk)

add_library(vk STATIC vk_client.cpp vk_request.cpp vk_response.cpp)

target_include_directories(vk PUBLIC headers/Base headers/VK) 




