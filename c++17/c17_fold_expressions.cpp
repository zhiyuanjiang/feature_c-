/*
*   折叠表达式: 一元右折叠、一元左折叠、二元右折叠、二元左折叠
*/

#include <iostream>

/*
*  二元左折叠
*/
template<typename FIRST, typename ...T>
FIRST add_binary_left_fold(FIRST f, T ...ts) {
    return (f + ... + ts);
}

/*
*  二元右折叠
*/
template<typename FIRST, typename ...T>
FIRST add_binary_right_fold(FIRST f, T ...ts) {
    return (ts + ... + f);
}

/*
*  一元左折叠
*/
template<typename ...T>
auto add_unary_left_fold(T ...ts) {
    return (... + ts);
}

/*
*  一元右折叠
*/
template<typename ...T>
auto add_unary_right_fold(T ...ts) {
    return (ts + ...);
}

int main() {
    int a = add_binary_left_fold(1, 2, 3);
    std::cout << a << std::endl;
    a = add_binary_right_fold(1, 2);
    std::cout << a << std::endl;
    a = add_unary_left_fold(1, 2, 3, 4);
    std::cout << a << std::endl;
    a = add_unary_right_fold(1);
    std::cout << a << std::endl;
    return 0;
}