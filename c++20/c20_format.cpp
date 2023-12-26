/*
*   format 格式打印
*/ 

#include <iostream>
#include <format>

int main() {
    std::cout << std::format("{} {}", "hello", "world") << std::endl;
    return 0;
}