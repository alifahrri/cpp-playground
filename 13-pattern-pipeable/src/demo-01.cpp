/* https://cppinsights.io/s/9c2bf5a6 */

#include <vector>
#include <iostream>
#include <type_traits>

#define REQUIRES(...) typename=typename std::enable_if<(__VA_ARGS__)>::type

namespace demo {

    template <typename F>
    struct pipe_closure : F {
        template <typename ...Args>
        pipe_closure(Args&&...args) : F(std::forward<Args>(args)...)
        {}
    };

    template <typename T>
    struct wrapper {
        T value;

        template <typename X, REQUIRES(std::is_convertible<T,X>::value)>
        wrapper(X&& x) : value(std::forward<X>(x))
        {}

        T get() const
        {
            return std::move(value);
        }
    };

    template <typename T>
    auto make_wrapper(T&& x)
    {
        return wrapper<T>(std::forward<T>(x));
    }

    template <typename F>
    auto make_pipe_closure(F f) {
        return pipe_closure<F>(std::move(f));
    }

    template <typename F>
    struct pipeable {
        template <typename ...Args>
        auto operator()(Args&&...args) const {
            return make_pipe_closure([=](auto x) {
                return F()(x, args...);
            });
        }
    };

    template <typename F>
    struct pipeablev2 {
        template <typename ...Args>
        auto operator()(Args&&...args) const {
            return make_pipe_closure([=](auto... ws){
                return [=](auto &&x) -> decltype(auto) {
                    return F()(x, ws.get()...);
                };
            })(make_wrapper(std::forward<Args>(args)...));
        }
    };

    template <typename T, typename F>
    decltype(auto) operator|(T&& x, const pipe_closure<F> &p) {
        return p(std::forward<T>(x));
    };

    template <typename T, typename F>
    decltype(auto) operator|(T&& x, const pipeablev2<F> &p) {
        return F()(std::forward<T>(x));
    };

    namespace func {
        struct add_one {
            template <typename T>
            decltype(auto) operator()(T x) const {
                return x + 1;
            }
        };

        struct sum {
            template <typename T, typename U>
            decltype(auto) operator()(T x, U y) const {
                return x + y;
            }
        };
    }
}

int main(int argc, char **argv)
{
    {
        auto add_one = demo::pipe_closure<demo::func::add_one>();
        auto i = 1 | add_one | add_one;
        std::cout << i << std::endl;
    }
    {
        constexpr auto sum = demo::pipeable<demo::func::sum>{};
        auto i = 1 | sum(2);
        std::cout << i << std::endl;
    }
    {
        auto add_one = demo::pipeablev2<demo::func::add_one>{};
        auto i = 1 | add_one | add_one;
        std::cout << i << std::endl;
    }
    return 0;
}