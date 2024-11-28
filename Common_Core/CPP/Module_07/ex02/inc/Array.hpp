#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class   Array 
{
    private:
        T*              arr_;
        unsigned int    size_;

    public:
        Array();
        Array(unsigned int size);
        Array(const Array<T> &other);
        Array<T> &operator = (const Array<T> &other);
        ~Array();

        unsigned int size(void) const;

        T &operator [] (unsigned int index);
        const T &operator [] (unsigned int index) const;

};

template <typename T>
std::ostream &operator << (std::ostream &out, const Array<T> &array);

#include "Array.tpp"

#endif
