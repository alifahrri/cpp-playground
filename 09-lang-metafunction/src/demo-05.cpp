#include <iostream>

constexpr size_t pascal_triangle(size_t n /* row */, size_t k /* col */) {
    return (n==0) && (k==0) ? 1 
        : (k<=0) || (k==n) ? 1
        : pascal_triangle(n-1, k-1) + pascal_triangle(n-1,k);
}

int main(int argv, char **argc) 
{
    /* 1 */
    static_assert(pascal_triangle(0,0)==1);
    /* 1 1 */
    static_assert(pascal_triangle(1,0)==1);
    static_assert(pascal_triangle(1,1)==1);
    /* 1 2 1 */
    static_assert(pascal_triangle(2,0)==1);
    static_assert(pascal_triangle(2,1)==2);
    static_assert(pascal_triangle(2,2)==1);
    /* 1 3 3 1 */
    static_assert(pascal_triangle(3,0)==1);
    static_assert(pascal_triangle(3,1)==3);
    static_assert(pascal_triangle(3,2)==3);
    static_assert(pascal_triangle(3,3)==1);
    /* ... */
    /* 1 7 21 35 35 21 7 1 */
    static_assert(pascal_triangle(7,0)==1);
    static_assert(pascal_triangle(7,1)==7);
    static_assert(pascal_triangle(7,2)==21);
    static_assert(pascal_triangle(7,3)==35);
    static_assert(pascal_triangle(7,4)==35);
    static_assert(pascal_triangle(7,5)==21);
    static_assert(pascal_triangle(7,6)==7);
    static_assert(pascal_triangle(7,7)==1);
    std::cout << pascal_triangle(7,0) << " "
        << pascal_triangle(7,1) << " "
        << pascal_triangle(7,2) << " "
        << pascal_triangle(7,3) << " "
        << pascal_triangle(7,4) << " "
        << pascal_triangle(7,5) << " "
        << pascal_triangle(7,6) << " "
        << pascal_triangle(7,7) << std::endl;
}