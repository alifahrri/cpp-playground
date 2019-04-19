#include "elements.hpp"
#include "helper.hpp"
#include <iostream>
#include <cmath>
#include <array>
#include <vector>

#define print(EXPR) std::cout << #EXPR << " : " << EXPR << std::endl;

namespace elm = elements;

int main(int argc, char**argv)
{
    Point1<double> p1;
    Point2<double> p2;
    Point3<double> p3;
    Point4<double> p4;

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

    elm::x(p1) = M_PI;
    elm::x(p2) = elm::x(p1);
    elm::x(p3) = elm::x(p1) * elm::x(p2);
    elm::x(p4) = elm::x(p3) + M_PI_2;
    elm::x(raw_point) = elm::x(p4) / (-elm::x(p4));
    elm::x(vector_point) = elm::x(raw_point) + M_PI;
    elm::x(array_point) = elm::x(vector_point) - elm::x(p1);

    /* check values for each point type */
    print(elm::x(p1));
    print(elm::x(p2));
    print(elm::x(p3));
    print(elm::x(p4));
    print(elm::x(raw_point));
    print(elm::x(vector_point));
    print(elm::x(array_point));

    return 0;
}