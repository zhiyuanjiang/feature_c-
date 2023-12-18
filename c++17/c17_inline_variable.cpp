/*
* 内联变量
*/

#include <iostream>

class Test {
public:
    inline static int a = 10;
};

int main() {
    Test t;
    std::cout << t.a << std::endl;
    return 0;
}