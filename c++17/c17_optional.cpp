/*
*   std::optional
*/ 

#include <iostream>
#include <optional>

std::optional<std::string> test(int a) {
    if(a == 0){
        return "hello";
    }else{
        return std::nullopt;
    }
} 

int main() {
    std::optional<std::string> a = test(0);
    if(a){
        std::cout << *a << std::endl;
    }else{
        std::cout << "exception" << std::endl;
    }

    std::optional<std::string> b = std::make_optional("hello");
    if(b){
        std::cout << *b << std::endl;
    }

    std::optional<std::string> c;
    if(!c){
        std::cout << "no value" << std::endl;
    }
    return 0;
}