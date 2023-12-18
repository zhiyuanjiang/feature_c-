#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <charconv>

int main() {
    std::string str{"123456098"};
    int value = 0;
    std::from_chars(str.data(), str.data() + 4, value);
    std::cout << value << std::endl;
    str = std::string("12.34");
    double val = 0;
    std::from_chars(str.data(), str.data() + str.length(), val);
    std::cout << val << std::endl;
    str = std::string("xxxxxxxx");
    const int v = 1234;
    std::to_chars(str.data(), str.data() + str.size(), v);
    std::cout << str << std::endl;
}