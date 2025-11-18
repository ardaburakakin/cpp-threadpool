#pragma once

#include <vector>
#include <thread>
#include <functional>
#include <future>
#include <type_traits>

#include "ThreadSafeQueue.h"

class ThreadPool {
public:
    explicit ThreadPool(std::size_t thread_count);
    ~ThreadPool();

    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;

    template <class F, class... Args>
    auto submit(F&& f, Args&&... args)
        -> std::future<typename std::invoke_result<F, Args...>::type>
    {
        using return_type = typename std::invoke_result<F, Args...>::type;

        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );

        std::future<return_type> res = task->get_future();

        tasks_.push([task]() { (*task)(); });

        return res;
    }

private:
    void worker_loop();

    std::vector<std::thread> workers_;
    ThreadSafeQueue<std::function<void()>> tasks_;
};
