#include <iostream>
#include <ranges>

void test() {
    auto test_filter = [](int x) { return x%2 == 0; };
    auto test_transform = [](int x) { return x*x; };
    auto test_view = std::views::iota(0, 10) | std::views::filter(test_filter) | std::views::transform(test_transform);
    for(auto v : test_view){
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {

    test();

    return 0;
}