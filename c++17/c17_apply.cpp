/*
*   std::apply 可以将tuple展开作为函数的参数传入
*/

#include <iostream>
#include <tuple>

int add(int first, int second) { return first+second; }

int add_lambda(int first, int second) { return first+second; }

int main() {
    std::cout << std::apply(add, std::pair(1, 2)) << std::endl;
    std::cout << std::apply(add_lambda, std::tuple(2, 3)) << std::endl;
    return 0;
}