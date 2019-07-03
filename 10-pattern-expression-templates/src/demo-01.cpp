#include <iostream>
#include <vector>
#include <cassert>

template <typename E>
class VecExpression {
public:
    double operator[](size_t i) const {
        return static_cast<const E&>(*this)[i];
    }
    size_t size() const {
        return static_cast<const E&>(*this).size();
    }
};

class Vec : public VecExpression<Vec> {
    std::vector<double> elems;
public:
    double operator[](size_t i) const {
        return elems[i];
    }
    double &operator[](size_t i) {
        return elems[i];
    }
    size_t size() const { return elems.size(); }
    Vec(size_t n) : elems(n) {}

    Vec(std::initializer_list<double> init) {
        for(auto v : init) elems.push_back(v);
    }

    template <typename E>
    Vec(const VecExpression<E> &vec) : elems(vec.size()) {
        for (size_t i=0; i<vec.size(); i++) 
            elems[i] = vec[i];
    }
};

template <typename A, typename B>
class VecSum : public VecExpression<VecSum<A,B>> {
    const A &a;
    const B &b;
public:
    VecSum(const A &a, const B &b) : a(a), b(b) {
        assert(a.size()==b.size());
    }
    double operator[](size_t i) const {
        return a[i] + b[i];
    }
    size_t size() const {
        return a.size();
    }
};

template <typename A, typename B>
VecSum<A,B> operator+(const VecExpression<A> &a, const VecExpression<B> &b) {
    return VecSum<A,B>(*static_cast<const A*>(&a),*static_cast<const B*>(&b));
}

int main(int,char**)
{
    Vec a = {1, 2, 3};
    Vec b = {1, 2, 3};
    Vec c = {1, 2, 3};

    Vec d = a + b + c;
    for(size_t i=0; i<d.size(); i++) {
        std::cout << d[i] << ", ";
    }
    return 0;
}