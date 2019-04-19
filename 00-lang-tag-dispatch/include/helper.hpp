#ifndef HELPER_HPP
#define HELPER_HPP

template <typename T>
struct Point1 {
    T x;
    T y;
};

template <typename T>
struct Point2 {
    T p[2];
    const T& x() const { return p[0]; }
    const T& y() const { return p[1]; }
    T& x() { return p[0]; }
    T& y() { return p[1]; }
};

template <typename T>
struct Point3 {
    T p[2];
    const T& operator()(size_t i) const {
        return p[i];
    }
    T& operator()(size_t i) {
        return p[i];
    }
};

template <typename T>
struct Point4 {
    T p[2];
    const T& operator[](size_t i) const {
        return p[i];
    }
    T& operator[](size_t i) {
        return p[i];
    }
};

#endif // HELPER_HPP