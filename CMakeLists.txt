cmake_minimum_required(VERSION 3.22)
project(feature_c++)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pipe -fPIC -g")

# add_subdirectory(c++14)
add_subdirectory(c++17)
add_subdirectory(c++20)

add_executable(test test.cpp)