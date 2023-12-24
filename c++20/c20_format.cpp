#include <iostream>
#include <format>

int main() {
    std::cout << std::format("{} {}", "hello", "world") << std::endl;
    return 0;
}