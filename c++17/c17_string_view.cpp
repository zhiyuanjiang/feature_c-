/*
*   std::string_view 表示字符串的视图，记录一个指针和字符串长度，不会创建新的字符串。
*   对于只读的字符串可以使用string_view，效率更高。
*/

#include <iostream>
#include <string>
#include <chrono>

void print(std::string_view str) {
    std::cout << str << std::endl;
}

void test_cp_string() {
    auto start = std::chrono::system_clock::now();
    std::string test = "hello world";
    for(int i = 0; i < 100000; ++i){
        std::string tmp = test;
    }
    auto end = std::chrono::system_clock::now();
    std::cout << "cp string: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << std::endl;
}

void test_cp_string_view() {
    auto start = std::chrono::system_clock::now();
    std::string test = "hello world";
    for(int i = 0; i < 100000; ++i){
        std::string_view tmp = test;
    }
    auto end = std::chrono::system_clock::now();
    std::cout << "cp string view: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << std::endl;
}

int main() {
    print("hello world");
    test_cp_string();
    test_cp_string_view();
    return 0;
}