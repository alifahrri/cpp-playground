#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
#include <atomic>

std::atomic_int n_threads(0);
 
template <typename RandomIt, size_t chunk = 1000>
int parallel_sum(RandomIt beg, RandomIt end, std::launch policy = std::launch::async)
{
    std::cout << __FUNCTION__ << " : " << std::this_thread::get_id() << "\n";
    auto len = end - beg;
    /* each thread will accumulate iterator with the size of chunk */
    if (len < chunk)
        return std::accumulate(beg, end, 0);
 
    n_threads++;
    RandomIt mid = beg + len/2;
    auto handle = std::async(policy,
                             parallel_sum<RandomIt, chunk>, mid, end, policy);
    int sum = parallel_sum<RandomIt, chunk>(beg, mid, policy);
    return sum + handle.get();
}
 
int main()
{
    std::cout << "main thread id : " << std::this_thread::get_id() << std::endl;
    std::vector<int> v(10000, 1);
    std::cout << "parallel sum with async policy : " << std::endl;
    {
        auto sum = parallel_sum<decltype(v.begin()),4000>(v.begin(), v.end());
        std::cout << "The sum is " << sum << '\n';
        std::cout << "Computed on " << n_threads << " threads" << std::endl;
    }
    n_threads = 0;
    std::cout << "parallel sum with deferred policy : " << std::endl;
    {
        auto sum = parallel_sum<decltype(v.begin()),4000>(v.begin(), v.end(), std::launch::deferred);
        std::cout << "The sum is " << sum << '\n';
        // std::cout << "Computed on " << n_threads << " threads" << std::endl;
    }
}