#ifndef CHOICE_HPP
#define CHOICE_HPP

#include <cstdio>

// this object was used for resolving ambiguous call

template <std::size_t n>
struct choice : choice<n-1>
{};

template <>
struct choice<0> {};

#endif // CHOICE_HPP
