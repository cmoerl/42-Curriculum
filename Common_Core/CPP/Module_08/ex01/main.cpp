#include "Span.hpp"
#include <iostream>

int main()
{
    Span    sp(200);

    try {
        sp.addNumber(5);
        sp.addNumber(6);

        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;

        sp.printNumbers();

        sp.addSpecificNumbers(10, 50);

        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;

        sp.printNumbers();

        sp.addRandomNumbers(100, 500, 1000);

        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;

        sp.printNumbers();

        Span sp2(5);
        sp2.addNumber(1);
        sp2.addNumber(2);
        sp2.addNumber(3);
        sp2.addNumber(4);
        sp2.addNumber(5);

        std::cout << "Longest Span (sp2): " << sp2.longestSpan() << std::endl;
        std::cout << "Shortest Span (sp2): " << sp2.shortestSpan() << std::endl;

        sp2.printNumbers();

        try {
            sp2.addNumber(6);
        } catch (std::exception &e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        Span sp3(2);
        sp3.addNumber(1);
        try {
            std::cout << "Shortest Span (sp3): " << sp3.shortestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return (1);
    }

    return (0);
}
