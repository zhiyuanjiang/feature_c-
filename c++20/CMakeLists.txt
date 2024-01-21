set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -pipe -fPIC -g")
add_executable(c20_test c20_test.cpp)
add_executable(c20_format c20_format.cpp)
add_executable(c20_jthread c20_jthread.cpp)
add_executable(c20_ranges c20_ranges.cpp)

target_link_libraries(c20_jthread -lpthread)

add_subdirectory(coroutine)
add_subdirectory(concepts)
add_subdirectory(ranges)

