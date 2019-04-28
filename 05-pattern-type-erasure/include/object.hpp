#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <vector>
#include <string>
#include <memory>

class Concept {
public:
    virtual ~Concept() {}
    virtual std::string getName() const = 0;
};

template <typename T>
struct Model : public Concept{
    Model(const T& object) 
        : object(object) {}
    std::string getName() const {
        return object.getName();
    }
private:
    T object;
};

class Object {
public:
    template <typename T>
    Object(const T& object) 
        : object(std::make_shared<Model<T>>(std::move(object)))
    {}
    std::string getName() const {
        return object->getName();
    }
private:
    std::shared_ptr<Concept> object;
};

#endif // OBJECT_HPP