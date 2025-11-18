#include "ThreadPool.h"

ThreadPool::ThreadPool(std::size_t thread_count) {
    if (thread_count == 0) {
        thread_count = 1;
    }

    workers_.reserve(thread_count);

    for (std::size_t i = 0; i < thread_count; ++i) {
        workers_.emplace_back([this]() {
            this->worker_loop();
            });
    }
}

ThreadPool::~ThreadPool() {
    // Her thread için bir tane "boþ iþ" (sentinel) gönderiyoruz
    for (std::size_t i = 0; i < workers_.size(); ++i) {
        tasks_.push(std::function<void()>()); // boþ function: çýkýþ sinyali
    }

    for (auto& t : workers_) {
        if (t.joinable()) {
            t.join();
        }
    }
}

void ThreadPool::worker_loop() {
    while (true) {
        std::function<void()> task;
        tasks_.wait_and_pop(task);

        if (!task) {
            // Boþ iþ geldiyse: döngüden çýk
            break;
        }

        task();
    }
}
