#include <coroutine>
#include <iostream>

class task {
 public:
  class promise_type {
   public:
    task get_return_object() {
      return {std::coroutine_handle<promise_type>::from_promise(*this)};
    }
    std::suspend_never initial_suspend() { return {}; }
    // 这个例子中不需要在协程结束后保留相关资源，因此直接返回 std::suspend_never
    std::suspend_never final_suspend() noexcept { return {}; }
    void unhandled_exception() {}
    void return_void() {}
  };

  task(std::coroutine_handle<promise_type> handle) : _handle(handle) {}

  // 通过调用协程对象的 resume() 主动恢复协程
  void resume() { _handle.resume(); }

 private:
  std::coroutine_handle<promise_type> _handle;
};

// 一个简单的计数器，功能就是在每次恢复时计数一次
task counter() {
  std::suspend_always awaitable;
  for (size_t count = 0;; ++count) {
    // 同一个 awaitable 可以多次 co_await
    // 每次 co_await，都会将控制交还给调用者，也就是 main 函数
    co_await awaitable;
    std::cout << "current count: " << count << std::endl;
  }
}

int main(int argc, char* argv[]) {
  task counter_task = counter();
  for (int i = 0; i < 3; ++i) {
    std::cout << "resume counter task" << std::endl;
    // 主动调用 resume 以恢复协程
    counter_task.resume();
  }
  return 0;
}