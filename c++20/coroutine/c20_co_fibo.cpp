#include <iostream>
#include <coroutine>

class FiboCoroutine {
public:
    class FiboPromise {
    public:
        FiboCoroutine get_return_object() {
            return std::coroutine_handle<FiboPromise>::from_promise(*this);
        }
        // 由于是惰性生成器，我们在协程初始化时就暂停，所以返回std::suspend_always
        std::suspend_always initial_suspend() {
            return {};
        }
        std::suspend_never final_suspend() noexcept {
            return {};
        }
        void unhandled_exception() {

        }
        void return_void() {
            std::cout << "return void" << std::endl;
        }

        std::suspend_always yield_value(size_t value) {
            _value = value;
            std::cout << "yield value: " << value << std::endl;
            return {};
        }

        size_t _value = 0;
    };

    using promise_type = FiboPromise;
    FiboCoroutine(std::coroutine_handle<FiboPromise> handle) : _handle(handle) {}

    size_t get_val() {
        _handle.resume();
        return _handle.promise()._value;
    }

private:
    std::coroutine_handle<FiboPromise> _handle;
};

FiboCoroutine get_fibo() {
    co_yield 1;
    co_yield 1;
    size_t p1 = 1;
    size_t p2 = 1;
    size_t p3 = 0;
    for(int i = 0; ; i++){
        p3 = p1 + p2;
        co_yield p3;
        p1 = p2; 
        p2 = p3;
    }
}

int main() {
    FiboCoroutine fibo = get_fibo();
    for(int i = 0; i < 10; ++i){
        size_t val = fibo.get_val();
        std::cout << "fibo " << i << " " << val << std::endl;
    }
    return 0;
}