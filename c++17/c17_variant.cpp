/*
*   std::variant  是一个可以存储多种不同类型值但一次只能存储一种类型值的模板类，
*      它类似于一个union类型，但是更加安全和易于使用。在错误的情况下variant不持有任何值。
*/
#include <iostream>
#include <variant>

int main() {
    std::variant<int, std::string> x = "abc";
    // index 获取当前variant持有变量的类型，返回该类型的索引
    std::cout << "index: " << x.index() << std::endl;
    // std::get 获取variant中该类型的值
    std::cout << std::get<std::string>(x) << std::endl;
    x = 123;
    std::cout << "index: " << x.index() << std::endl;
    std::cout << std::get<int>(x) << std::endl;
    return 0;
}