#ifndef ITER_HPP
#define ITER_HPP

#include <string>

template <typename T>
void    iter(T* address, int len, void (*fun)(T const &)) {
    for (int i = 0; i < len; i++)
        fun(address[i]);
}

#endif
