#include "iter.hpp"
#include <iostream>

template <typename T>
void    print(T const & x) {
    std::cout << x << std::endl;
}

int main()
{
    char   arr1[] = {'a', 'b', 'c', 'd', 'e'};
    int    arr2[] = {1, 2, 3, 4, 5};
    double arr3[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    iter(arr1, 5, print);
    iter(arr2, 5, print);
    iter(arr3, 5, print);

    return (0);
}
