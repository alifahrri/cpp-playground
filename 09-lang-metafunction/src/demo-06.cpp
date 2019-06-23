#include <iostream>

namespace detail {
    template <int N, int K, bool> struct pascal_triangle {};

    template <int N, int K>
    struct pascal_triangle<N,K,false> {
        enum { value = pascal_triangle<N-1,K-1,(K-1)==(N-1)>::value + pascal_triangle<N-1,K,K==(N-1)>::value };
    };

    template <>
    struct pascal_triangle<0,0,true> {
        enum { value = 1 };
    };

    template <int N, int K>
    struct pascal_triangle <N,K,true> {
        enum { value = 1 };
    };

    template <int N>
    struct pascal_triangle <N,0,false> {
        enum { value = 1 };
    };
} // namespace detail

template <int N, int K> 
struct pascal_triangle {
    enum { value = detail::pascal_triangle<N,K,K==N>::value };
};

int main(int argc, char ** argv)
{
    /* 1 */
    static_assert(pascal_triangle<0,0>::value==1);
    /* 1 1 */
    static_assert(pascal_triangle<1,0>::value==1);
    static_assert(pascal_triangle<1,1>::value==1);
    /* 1 2 1 */
    static_assert(pascal_triangle<2,0>::value==1);
    static_assert(pascal_triangle<2,1>::value==2);
    static_assert(pascal_triangle<2,2>::value==1);
    /* ... */
    /* 1 7 21 35 35 21 7 1 */
    static_assert(pascal_triangle<7,0>::value==1);
    static_assert(pascal_triangle<7,1>::value==7);
    static_assert(pascal_triangle<7,2>::value==21);
    static_assert(pascal_triangle<7,3>::value==35);
    static_assert(pascal_triangle<7,4>::value==35);
    static_assert(pascal_triangle<7,5>::value==21);
    static_assert(pascal_triangle<7,6>::value==7);
    static_assert(pascal_triangle<7,7>::value==1);
    std::cout << pascal_triangle<7,0>::value << " "
        << pascal_triangle<7,1>::value << " "
        << pascal_triangle<7,2>::value << " "
        << pascal_triangle<7,3>::value << " "
        << pascal_triangle<7,4>::value << " "
        << pascal_triangle<7,5>::value << " "
        << pascal_triangle<7,6>::value << " "
        << pascal_triangle<7,7>::value << std::endl;
}