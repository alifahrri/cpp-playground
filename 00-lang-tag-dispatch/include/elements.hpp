#ifndef ELEMNENTS_HPP
#define ELEMNENTS_HPP

#include <cstdio>

// this object was used for resolving ambiguous call
template <std::size_t n>
struct choice : choice<n-1>
{};
template <>
struct choice<0> {};

namespace elements {
    namespace detail {
        template <typename T1, size_t order=3>
        auto x(choice<order>, T1& p) -> decltype((p.x)) {
            return p.x;
        }
        template <typename T1, size_t order=2>
        auto x(choice<order>, T1& p) -> decltype((p.x())) {
            return p.x();
        }
        template <typename T1, size_t order=1>
        auto x(choice<order>, T1& p) -> decltype((p(0))) {
            return p(0);
        }
        template <typename T1, size_t order=0>
        auto x(choice<order>, T1& p) -> decltype((p[0])) {
            return p[0];
        }
        // const overload
        template <typename T1, size_t order=3>
        const auto x(choice<order>, const T1& p) -> decltype(p.x) {
            return p.x;
        }
        template <typename T1, size_t order=2>
        const auto x(choice<order>, const T1& p) -> decltype(p.x()) {
            return p.x();
        }
        template <typename T1, size_t order=1>
        const auto x(choice<order>, const T1& p) -> decltype(p(0)) {
            return p(0);
        }
        template <typename T1, size_t order=0>
        const auto x(choice<order>, const T1& p) -> decltype(p[0]) {
            return p[0];
        }
    }
    // entry point for x
    template <typename T, size_t n_choice=3>
    auto x(T& p) -> decltype((detail::x<T>(choice<n_choice>{},p)))
    {
        return detail::x(choice<n_choice>{},p);
    }
    template <typename T, size_t n_choice=3>
    const auto x(const T& p) -> decltype((detail::x<T>(choice<n_choice>{},p)))
    {
        return detail::x(choice<n_choice>{},p);
    }
}

#endif // ELEMNENTS_HPP