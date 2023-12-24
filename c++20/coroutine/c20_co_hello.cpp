#include <coroutine>
#include <iostream>

struct HelloCoroutine {
    struct HelloPromise {
        HelloCoroutine get_return_object() {
            std::cout << "==============call get_return_object==============" << std::endl;
            return std::coroutine_handle<HelloPromise>::from_promise(*this);
        }
        std::suspend_never initial_suspend() {
            std::cout << "==============call initial_suspend==============" << std::endl;
            return {}; 
        }

        std::suspend_always final_suspend() noexcept {
            std::cout << "==============call final_suspend==============" << std::endl;
            return {}; 
        }
        void unhandled_exception() {}
    };

    using promise_type = HelloPromise;
    HelloCoroutine(std::coroutine_handle<HelloPromise> h) : handle(h) {}

    std::coroutine_handle<HelloPromise> handle;
};

std::coroutine_handle<> coroutine_handle;
struct AWaitableObject
{
    AWaitableObject() {}

    bool await_ready() const { 
        std::cout << "==============call await_ready==============" << std::endl;
        return false; 
    }

    int await_resume() { 
        std::cout << "==============call await_resume==============" << std::endl;
        return 0; 
    }

    void await_suspend(std::coroutine_handle<> handle) {
        std::cout << "==============call await_suspend==============" << std::endl;
        coroutine_handle = handle;
    }

};

HelloCoroutine hello() {
    std::cout << "Hello " << std::endl;
    co_await AWaitableObject{};
    std::cout << "world!" << std::endl;
}

int main() {
    std::cout << "start" << std::endl;

    HelloCoroutine coro = hello();

    std::cout << "calling resume" << std::endl;
    coro.handle.resume();

    std::cout << "destroy" << std::endl;
    coro.handle.destroy();

    return 0;
}
