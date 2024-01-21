#include <iostream>
#include <type_traits>

// 原始定义。
template<class T>
struct TestIntegral : public std::false_type {
};

// 限制T是一个整形，这是个偏特化版本
template<class T>
requires std::is_integral_v<T>
struct TestIntegral<T> : public std::true_type {
};

template<class T>
bool constexpr TestIntegralV = TestIntegral<T>::value;

struct S {

};

int main() {

    // 会优先选择偏特化的版本
    std::cout << TestIntegralV<int> << std::endl;
    std::cout << TestIntegralV<S> << std::endl;

    return 0;
}