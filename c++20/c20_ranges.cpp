#include <iostream>
#include <ranges>
#include <vector>

void test() {
    std::vector<int> data{1, 2, 3, 4, 5, 6};
    auto res = data | std::views::filter([](int n){ return n%2 == 0; }) 
        | std::views::transform([](int n){ return n*2; });
    for(auto v : res){
        std::cout << v << std::endl;
    }
}

int main() {
    test();

    for(int i : std::views::iota(2, 10)){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}