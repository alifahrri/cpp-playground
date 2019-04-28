#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
#include <atomic>

std::atomic_int n_threads(0);
 
template <typename RandomIt>
int parallel_sum(RandomIt beg, RandomIt end)
{
    std::cout << __PRETTY_FUNCTION__ << " : " << std::this_thread::get_id() << std::endl;
    auto len = end - beg;
    if (len < 1000)
        return std::accumulate(beg, end, 0);
 
    n_threads++;
    RandomIt mid = beg + len/2;
    auto handle = std::async(std::launch::async,
                             parallel_sum<RandomIt>, mid, end);
    int sum = parallel_sum(beg, mid);
    return sum + handle.get();
}
 
int main()
{
    std::vector<int> v(10000, 1);
    auto sum = parallel_sum(v.begin(), v.end());
    std::cout << "The sum is " << sum << '\n';
    std::cout << "Computed on " << n_threads << " threads" << std::endl;
}