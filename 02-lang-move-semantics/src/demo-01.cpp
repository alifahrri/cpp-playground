#include "helper.hpp"

#define print(EXPR) std::cout << #EXPR << " => "; EXPR;
#define print_str(STR) std::cout << #STR << " : " << STR << std::endl;

int main(int argc, char** argv)
{
    print(String0 s1("s1"));
    print(String0 s2(s1));
    print(String0 s3 = s1);
    print(String0 s4((String0&&)s3));
    print(String0 s5(String0("s5")));
    print(String0 s6(std::move(s5)));
    print(String0 s7(s1+s2));
    print(String0 s8(std::move(s1+s2)));

    print_str(s1);
    print_str(s2);
    print_str(s3);
    print_str(s4);
    print_str(s5);
    print_str(s6);
    print_str(s7);
    print_str(s8);

    return 0;
}