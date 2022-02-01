cmake_minimum_required(VERSION 3.10)

project(LeetCode VERSION 1.0)

set (CMAKE_CXX_STANDARD 17)

include_directories(PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()
add_subdirectory(tests)