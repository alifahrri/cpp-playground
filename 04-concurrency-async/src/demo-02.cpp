#include <iostream>
#include <vector>
#include <atomic>
#include <future>

template <typename T>
struct F 
{
    T operator()() { return T(0); }
    template <typename...Args>
    T operator()(const T& v, Args ...args) {
        auto id = std::this_thread::get_id();
        std::cout << __PRETTY_FUNCTION__ << " : " << id << std::endl;
        return v + operator()((T)args...);
    }
};

int main(int argc, char**argv)
{
    std::cout << "main thread id : " << std::this_thread::get_id() << std::endl;
    F<int> f0;
    F<double> f1;
    std::vector<std::future<int>> f0_handles;
    std::vector<std::future<double>> f1_handles;
    f0_handles.emplace_back(std::async(std::launch::async, f0, 3));
    f0_handles.emplace_back(std::async(std::launch::async, f0, 3, 4, 5));
    f0_handles.emplace_back(std::async(std::launch::async, f0, 1.9, -9.1));
    f0_handles.emplace_back(std::async(std::launch::deferred, f0, 2, 8, 6, 9));
    int isum(0);
    for(auto &h : f0_handles) {
        auto s = h.get();
        isum += s;
        std::cout << "s : " << s << std::endl;
    }
    std::cout << "sum : " << isum << std::endl;
    return 0;
}