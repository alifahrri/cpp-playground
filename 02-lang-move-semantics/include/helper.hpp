#ifndef HELPER_HPP
#define HELPER_HPP

#include <cstring>
#include <algorithm>
#include <iostream>

class String0 
{
    char* data;
public:
    String0(const char* str)
    {
        std::cout << "[" << this << "] : ";
        std::cout << "constructor called!" << std::endl;
        size_t size = strlen(str) + 1;
        data = new char[size];
        memcpy(data, str, size);
    }

    String0(char*&& str)
    {
        std::cout << "[" << this << "] : ";
        std::cout << "constructor (move char) called!" << std::endl;
        std::swap(data, str);
    }

    /* rule of three */
    /* destructor */
    ~String0()
    {
        std::cout << "[" << this << "] : ";
        std::cout << "destructor called!" << std::endl;
        delete [] data;
    }
    /* copy constructor */
    String0(const String0 &other) 
    {
        std::cout << "[" << this << "] : ";
        std::cout << "copy constructor called!" << std::endl;
        size_t size = strlen(other.data) + 1;
        data = new char[size];
        memcpy(data, other.data, size);
    }
    /* copy assignment operator */
    String0& operator=(const String0 &other)
    {
        std::cout << "[" << this << "] : ";
        std::cout << "copy operator called!" << std::endl;
        if(this != &other) { // prevent invalid self-assignment
            size_t size = strlen(other.data) + 1;
            delete [] data;
            data = new char[size];
            memcpy(data, other.data, size);
        }
        return *this;
    }

    /* rule of five */
    /* move constructor */
    String0(String0 &&other)
    {
        std::cout << "[" << this << "] : ";
        std::cout << "move contructor called!" << std::endl;
        std::swap(data, other.data);
        other.data = nullptr;
    }
    /* move assignment operator */
    String0& operator=(String0&& other) 
    {
        std::cout << "[" << this << "] : ";
        std::cout << "move operator called!" << std::endl;
        if(this != &other) { // prevent self-assignment
            std::swap(data, other.data);
            other.data = nullptr;
        }
        return *this;
    }

    /* define operator + (for testing) */
    String0 operator+(const String0& other) 
    {
        std::cout << "[" << this << "] : ";
        std::cout << "operator + called!" << std::endl;
        size_t size = strlen(data) + strlen(other.data) + 2;
        char *data = new char[size];
        strcat(data, this->data);
        strcat(data, other.data);
        return String0(data);
    }

    friend std::ostream& operator << (std::ostream &out, const String0 &str);
};

std::ostream& operator << (std::ostream &out, const String0 &str)
{
    if(str.data) out << str.data;
    return out;
}

#endif // HELPER_HPP