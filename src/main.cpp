#include <iostream>
#include <vector>
#include <chrono>
#include <thread>   

#include "ThreadPool.h"

int slow_square(int x) {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    return x * x;
}

int main() {
    std::cout << "Thread pool ornegi basliyor...\n";

    ThreadPool pool(4); // 4 thread'li havuz

    std::vector<std::future<int>> results;

    for (int i = 1; i <= 8; ++i) {
        results.push_back(
            pool.submit(slow_square, i)
        );
    }

    for (std::size_t i = 0; i < results.size(); ++i) {
        std::cout << "Sonuc " << i + 1 << ": " << results[i].get() << "\n";
    }

    std::cout << "Bitti.\n";
    return 0;
}
