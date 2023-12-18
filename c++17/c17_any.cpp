/*
*   std::any 是一种可以存储任意可拷贝构造类型值的类型安全容器。
*/

#include <iostream>
#include <any>

int main() {

    std::any a = 1;
    std::cout << a.type().name() << " " << std::any_cast<int>(a) << std::endl;
    a = 3.14;
    std::cout << a.type().name() << " " << std::any_cast<double>(a) << std::endl;
    return 0;
}