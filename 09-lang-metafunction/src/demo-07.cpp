#include <iostream>
#include <cmath>

namespace detail {
    constexpr size_t factorial(size_t n) {
        return n > 0 ? n * factorial(n-1) : 1;
    }
    template <size_t N, typename Scalar>
    constexpr Scalar taylor_series(Scalar a, Scalar h) {
        return 0;
    }

    template <size_t N, typename Scalar, typename F>
    constexpr Scalar taylor_series(Scalar a, Scalar h, const F &f) {
        return (f(a) * std::pow(h,N) / factorial(N));
    }

    template <size_t N, typename Scalar, typename F, typename ...DFs>
    constexpr Scalar taylor_series(Scalar a, Scalar h, const F &f, const DFs& ... dfs) {
        return (f(a) * std::pow(h,N) / factorial(N)) + taylor_series<N+1,Scalar>(a,h,dfs...);
    }
}

template <typename Scalar, typename F, typename ...DFs>
constexpr Scalar taylor_series(Scalar x, Scalar a, const F &f, const DFs& ...dfs) {
    return f(a) + detail::taylor_series<1,Scalar>(a,x-a,dfs...);
}

namespace cos_fn {
    constexpr double f0(double a) {
        /* evaluate at pi/4 */
        return cos(M_PI/4);
    }

    constexpr double f1(double a) {
        /* evaluate at pi/4 */
        return -sin(M_PI/4);
    }

    constexpr double f2(double a) {
        /* evaluate at pi/4 */
        return -cos(M_PI/4);
    }

    constexpr double f3(double a) {
        /* evaluate at pi/4 */
        return sin(M_PI/4);
    }

    constexpr double f4(double a) {
        /* evaluate at pi/4 */
        return cos(M_PI/4);
    }
}

#define PRINT(t, c, d) std::cout << #t << ": " << t << "; " << #c << ": " << c << "; " << #d << ": " << d << std::endl;
int main(int argc, char **argv)
{
    constexpr double c0 = cos(M_PI/4);
    constexpr double c1 = c0-(sin(M_PI/4)*(M_PI/12));
    constexpr double c2 = c1-(cos(M_PI/4)/2*std::pow(M_PI/12,2));
    constexpr double c3 = c2+(sin(M_PI/4)/6*std::pow(M_PI/12,3));
    constexpr double c4 = c3+(cos(M_PI/4)/24*std::pow(M_PI/12,4));

    /* compute taylor series */
    namespace fn = cos_fn;
    constexpr double t0 = taylor_series(M_PI/3,M_PI/4,fn::f0);
    constexpr double t1 = taylor_series(M_PI/3,M_PI/4,fn::f0,fn::f1);
    constexpr double t2 = taylor_series(M_PI/3,M_PI/4,fn::f0,fn::f1,fn::f2);
    constexpr double t3 = taylor_series(M_PI/3,M_PI/4,fn::f0,fn::f1,fn::f2,fn::f3);
    constexpr double t4 = taylor_series(M_PI/3,M_PI/4,fn::f0,fn::f1,fn::f2,fn::f3,fn::f4);

    /* define min difference */
    constexpr double zero = 1e-15;

    /* assert at compile time */
    static_assert(std::fabs(t0-c0)<zero);
    static_assert(std::fabs(t1-c1)<zero);
    static_assert(std::fabs(t2-c2)<zero);
    static_assert(std::fabs(t3-c3)<zero);
    static_assert(std::fabs(t4-c4)<zero);

    PRINT(t0,c0,t0-c0);
    PRINT(t1,c1,t1-c1);
    PRINT(t2,c2,t2-c2);
    PRINT(t3,c3,t3-c3);
    PRINT(t4,c4,t4-c4);
}