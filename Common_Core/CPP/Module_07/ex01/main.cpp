#include "iter.hpp"
#include <iostream>

void    print_char(char c) {
    std::cout << c << std::endl;
}

void    print_num(int i) {
    std::cout << i << std::endl;
}

int main()
{
    char   arr1[] = {'a', 'b', 'c', 'd', 'e'};
    int    arr2[] = {1, 2, 3, 4, 5};

    ::iter(arr1, 5, print_char);
    ::iter(arr2, 5, print_num);

    return (0);
}
