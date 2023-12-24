set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -pipe -fPIC -g")
add_executable(c20_test c20_test.cpp)
add_executable(c20_format c20_format.cpp)

add_subdirectory(coroutine)