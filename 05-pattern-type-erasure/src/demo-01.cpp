#include "object.hpp"
#include <iostream>

struct F00 {
    std::string getName() const {
        return std::string(__PRETTY_FUNCTION__);
    }
};

struct F01 {
    std::string getName() const {
        return std::string("fo1!");
    }
};

struct F02 {
    F02(std::string name) 
        : name(name)
    {}
    std::string getName() const {
        return name;
    }
    std::string name;
};

int main(int argc, char**argv)
{
    std::vector<Object> objects;
    objects.emplace_back(F00{});
    objects.emplace_back(F01{});
    objects.emplace_back(F02{"hello from F02!"});

    for(const auto& o : objects)
        std::cout << o.getName() << std::endl;
    return 0;
}