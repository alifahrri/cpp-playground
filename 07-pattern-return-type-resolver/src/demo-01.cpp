#include <random>
#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <set>

class RandomState
{
public:
    RandomState(size_t n) 
        : n(n) 
    {}
    template <typename ReturnType>
    operator ReturnType() {
        ReturnType r;
        std::random_device rd{};
        auto eng = std::mt19937(rd());
        auto gen = std::uniform_real_distribution<>(0,1);
        for(size_t i=0; i<n; i++)
            r.insert(r.end(), (typename ReturnType::value_type)gen(eng));
        return r;
    }
private:
    size_t n;
};

auto range_print(const auto& container)
{
    for(const auto &c : container)
        std::cout << c << " ";
}

int main(int argc, char **argv)
{
    std::vector<double> dvec = RandomState(10);
    // std::array<double,10> darr = RandomState(10);
    std::set<double> dset = RandomState(10);
    std::list<double> dlist = RandomState(10);
    
    std::cout << "vector : ";
    range_print(dvec);
    std::cout << std::endl;

    std::cout << "set : ";
    range_print(dset);
    std::cout << std::endl;

    std::cout << "list : ";
    range_print(dlist);
    std::cout << std::endl;
    return 0;
}