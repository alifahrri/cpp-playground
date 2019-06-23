#include <iostream>

constexpr size_t fibonacci(size_t n) {
    return n <= 1 ? n : fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char **argv)
{
    static_assert(fibonacci(0)==0);
    static_assert(fibonacci(1)==1);
    static_assert(fibonacci(2)==1);
    static_assert(fibonacci(10)==55);
    static_assert(fibonacci(20)==6765);
    std::cout << "fibonacci(0) : " << fibonacci(0) << std::endl;
    std::cout << "fibonacci(1) : " << fibonacci(1) << std::endl;
    std::cout << "fibonacci(2) : " << fibonacci(2) << std::endl;
    std::cout << "fibonacci(10) : " << fibonacci(10) << std::endl;
    std::cout << "fibonacci(20) : " << fibonacci(20) << std::endl;
}