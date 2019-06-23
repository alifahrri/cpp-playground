#include <iostream>

template <size_t N>
struct factorial {
    enum {
        value = N * factorial<N-1>::value
    };
};

template <>
struct factorial<0> {
    enum {
        value = 1
    };
};

int main(int argc, char **argv)
{
    static_assert(factorial<3>::value == 6);
    static_assert(factorial<5>::value == 120);
    std::cout << "factorial<3>::value : " << factorial<3>::value << std::endl;
    std::cout << "factorial<5>::value : " << factorial<5>::value << std::endl;
}