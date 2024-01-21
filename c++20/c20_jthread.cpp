/*
* jthread用起来和thread差不多，jthread主要新增了两个功能
* 1. jthread对象被析构，会主动调用join，相比thread更加安全，如果thread忘记join或者detach，就会core dump。
* 2. jthread支持外部请求终止，利用stop_token，stop_source。
*/

#include <iostream>
#include <thread>

using namespace std::chrono_literals;

void test_auto_join_jthread() {
    std::jthread t([]{
        std::cout << "test auto join jthread" << std::endl;
        std::this_thread::sleep_for(2s);
    });
}

void test_interrupt_jthread() {
    std::jthread t([](std::stop_token token){
        while(!token.stop_requested()){
            std::cout << "noninterrupt..." << std::endl;
            std::this_thread::sleep_for(1s);
        }
    });
    std::this_thread::sleep_for(2s);
    t.request_stop();
    std::cout << "send interruptable signal" << std::endl;
}

void test_stop_source_jthread() {
    std::jthread A([](std::stop_token token){
        while(!token.stop_requested()){
            std::cout << "running..." << std::endl;
            std::this_thread::sleep_for(1s);
        }
        std::cout << "stop running A" << std::endl;
    });
    // 利用stop_source在另一个线程B中终止线程A
    std::stop_source stop_source = A.get_stop_source();
    std::jthread B([](std::stop_source stop_source){
        std::this_thread::sleep_for(2s);
        std::cout << "this is B jthread send interruptable signal to A" << std::endl;
        stop_source.request_stop();
    }, stop_source);
}

int main() {
    test_auto_join_jthread();
    test_interrupt_jthread();
    test_stop_source_jthread();
    return 0;
}