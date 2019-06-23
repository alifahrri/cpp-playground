#include <cmath>
#include <iostream>

constexpr size_t factorial(size_t n) {
    return n > 0 ? n * factorial(n-1) : 1;
}

int main(int argc, char **argv) {
    static_assert(factorial(3)==6);
    static_assert(factorial(5)==120);
    std::cout << "factorial(3) : " << factorial(3) << std::endl;
    std::cout << "factorial(5) : " << factorial(5) << std::endl;
}