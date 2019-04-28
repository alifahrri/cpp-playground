#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

// std::atomic_bool ready(false);
std::atomic_bool ready(true);

void count1m(int id) {
    while(!ready) {
        std::this_thread::yield();
    }
    for(int i=0; i<1000000000; ++i) {}
    std::cout << id << std::endl;
}

int main(int argc, char **argv)
{
    // auto n_threads(20);
    auto n_threads(std::thread::hardware_concurrency());
    std::vector<std::thread> threads;
    for(size_t i=0; i<n_threads; i++) {
        threads.emplace_back(count1m, i);
    }
    // ready = true;
    for(auto &thread : threads) 
        thread.join();
    return 0;
}