#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <cstddef>

template <typename T>
void    iter(T* address, size_t len, void (*fun)(T const &)) {
    for (size_t i = 0; i < len; i++)
        fun(address[i]);
}

#endif
