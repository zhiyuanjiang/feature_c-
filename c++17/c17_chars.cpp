/*
*   新增两个字符串转换函数: std::to_chars(), std::from_chars()
*/

#include <iostream>
#include <charconv>
#include <string>
#include "sys/time.h"

uint64_t get_current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000.0;
}

void test_to_int() {
    std::string test = "123456";
    uint64_t start = get_current_time();
    int val = 0;
    for(int i = 0; i < 1000000; ++i){
        std::from_chars(test.c_str(), test.c_str()+test.length(), val);
    }
    uint64_t end = get_current_time();
    std::cout << "time: " << end - start << std::endl;
}

void test_to_int_old() {
    std::string test = "123456";
    uint64_t start = get_current_time();
    int val = 0;
    for(int i = 0; i < 1000000; ++i){
        val = std::stoi(test);
    }
    uint64_t end = get_current_time();
    std::cout << "old time: " << end - start << std::endl;
}

void test_to_float() {
    std::string test = "12.3456";
    uint64_t start = get_current_time();
    float val = 0;
    for(int i = 0; i < 1000000; ++i){
        std::from_chars(test.c_str(), test.c_str()+test.length(), val);
    }
    uint64_t end = get_current_time();
    std::cout << "time: " << end - start << std::endl;
}

void test_to_float_old() {
    std::string test = "12.3456";
    uint64_t start = get_current_time();
    float val = 0;
    for(int i = 0; i < 1000000; ++i){
        val = std::stof(test);
    }
    uint64_t end = get_current_time();
    std::cout << "old time: " << end - start << std::endl;
}

int main() {
    // 感觉新函数速度还慢一些
    test_to_int();
    test_to_int_old();
    test_to_float();
    test_to_float_old();
    return 0;
}