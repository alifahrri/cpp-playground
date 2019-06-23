#include <iostream>

template <size_t N>
struct fibonacci {
    enum {
        value = fibonacci<N-1>::value + fibonacci<N-2>::value
    };
};

template <>
struct fibonacci<1> {
    enum { value = 1 };
};

template <>
struct fibonacci<0> {
    enum { value = 0 };
};

int main(int argc, char **argv)
{
    static_assert(fibonacci<0>::value==0);
    static_assert(fibonacci<1>::value==1);
    static_assert(fibonacci<2>::value==1);
    static_assert(fibonacci<10>::value==55);
    static_assert(fibonacci<20>::value==6765);
    std::cout << "fibonacci<0>::value : " << fibonacci<0>::value << std::endl;
    std::cout << "fibonacci<1>::value : " << fibonacci<1>::value << std::endl;
    std::cout << "fibonacci<2>::value : " << fibonacci<2>::value << std::endl;
    std::cout << "fibonacci<10>::value : " << fibonacci<10>::value << std::endl;
    std::cout << "fibonacci<20>::value : " << fibonacci<20>::value << std::endl;
}