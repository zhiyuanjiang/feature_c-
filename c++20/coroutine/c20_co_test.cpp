#include <iostream>
#include <coroutine>

class MyCoroutine {
public:
    class MyPromise {
        public:
            MyCoroutine get_return_object() {
                std::cout << "get coroutine handle" << std::endl;
                return std::coroutine_handle<MyPromise>::from_promise(*this);
            }
            std::suspend_never initial_suspend() {
                std::cout << "initial suspend" << std::endl;
                return {};
            }
            std::suspend_never final_suspend() noexcept {
                std::cout << "final suspend" << std::endl;
                return {};
            }
            void unhandled_exception() {

            }
            void return_void() {
                std::cout << "return void" << std::endl;
            }
    };

    using promise_type = MyPromise;
    MyCoroutine(std::coroutine_handle<MyPromise> handle) : _handle(handle) {}

    void resume() {
        _handle.resume();
        std::cout << "MyCoroutine resume" << std::endl;
    }

private:
    std::coroutine_handle<MyPromise> _handle;
};

class MyAwaitable {
public:
    MyAwaitable() = default;

    bool await_ready() {
        std::cout << "await ready" << std::endl;
        return false;
    }
    void await_suspend(std::coroutine_handle<> handle) {
        std::cout << "await suspend" << std::endl;
    }
    void await_resume() {
        std::cout << "await resume" << std::endl;
    }
};

MyCoroutine test_my_coroutine() {
    std::cout << "start my coroutine" << std::endl;
    co_await MyAwaitable{};
    std::cout << "end my coroutine" << std::endl;
}

int main() {
    MyCoroutine my_routine = test_my_coroutine();
    my_routine.resume();
    return 0;
}