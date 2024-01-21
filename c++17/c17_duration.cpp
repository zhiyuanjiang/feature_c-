#include <iostream>
#include <chrono>

int main() {
    using namespace std::chrono_literals;
    std::chrono::duration time = 2s;
    std::cout << "test" << std::endl;
    return 0;  
}