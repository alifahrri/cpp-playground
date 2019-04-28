#include "elements.hpp"
#include "helper.hpp"
#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <random>

#define print(EXPR) std::cout << #EXPR << " : " << EXPR << std::endl;

namespace elm = elements;

auto f() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0,2.0);
    return dis(gen);
}

int main(int argc, char**argv)
{
    /* prepare placeholder */
    Point1<double> p1;
    Point2<double> p2;
    Point3<double> p3;
    Point4<double> p4;
    auto p1_ptr = new Point1<double>();
    double raw_point[2];
    std::vector<double> vector_point(5);
    std::array<double,7> array_point;

    /* check initial values for each point type */
    print(elm::x(p1));
    print(elm::x(p2));
    print(elm::x(p3));
    print(elm::x(p4));
    print(elm::x(raw_point));
    print(elm::x(vector_point));
    print(elm::x(array_point));
    print(elm::x(*p1_ptr));

    /* do something with the container */
    /* note that we could do operation across different types */
    elm::x(p1) = M_PI;
    elm::x(p2) = elm::x(p1);
    elm::x(p3) = elm::x(p1) * elm::x(p2);
    elm::x(p4) = elm::x(p3) + M_PI_2;
    elm::x(raw_point) = elm::x(p4) / (-elm::x(p4));
    elm::x(vector_point) = elm::x(raw_point) + M_PI;
    elm::x(array_point) = elm::x(vector_point) - elm::x(p1);
    elm::x(*p1_ptr) = (elm::x(p1) + elm::x(p4)) / (elm::x(p3) + M_PI + 2);

    /* check values for each point type */
    print(elm::x(p1));
    print(elm::x(p2));
    print(elm::x(p3));
    print(elm::x(p4));
    print(elm::x(raw_point));
    print(elm::x(vector_point));
    print(elm::x(array_point));
    print(elm::x(*p1_ptr));

    /* some random values */
    elm::x(p1) = f();
    print(elm::x(p1));

    return 0;
}