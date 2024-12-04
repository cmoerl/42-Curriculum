#include "Span.hpp"
#include <iostream>

int main()
{
    Span    sp;

    sp.addNumber(5);
    sp.addNumber(6);

    try {
        std::cout << sp.longestSpan() << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
    } catch (std::exception()) {
        std::cout << "Error" << std::endl;
    }

    return (0);
}
