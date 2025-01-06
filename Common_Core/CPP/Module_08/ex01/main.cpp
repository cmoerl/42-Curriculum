#include "Span.hpp"
#include <iostream>

int main()
{
    Span    test(5);

    try {
        std::cout << "--- main from subject ---" << std::endl;

        test.addNumber(6);
        test.addNumber(3);
        test.addNumber(17);
        test.addNumber(9);
        test.addNumber(11);

        std::cout << "Shortest Span: " << test.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << test.longestSpan() << std::endl;

    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    Span    sp(200);

    try {
        std::cout << "--- additional tests ---" << std::endl;

        std::cout << "--- Test 1 ---" << std::endl;

        sp.addNumber(5);
        sp.addNumber(6);

        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;

        sp.printNumbers();


        std::cout << "--- Test 2 ---" << std::endl;

        sp.addSpecificNumbers(10, 50);

        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;

        sp.printNumbers();


        std::cout << "--- Test 3 ---" << std::endl;

        sp.addRandomNumbers(100, 500, 1000);

        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;

        sp.printNumbers();


        std::cout << "--- Test 4 ---" << std::endl;
        Span sp2(5);
        sp2.addNumber(1);
        sp2.addNumber(2);
        sp2.addNumber(3);
        sp2.addNumber(4);
        sp2.addNumber(5);

        std::cout << "Longest Span (sp2): " << sp2.longestSpan() << std::endl;
        std::cout << "Shortest Span (sp2): " << sp2.shortestSpan() << std::endl;

        sp2.printNumbers();


        std::cout << "--- Test 5 ---" << std::endl;

        try {
            sp2.addNumber(6);
        } catch (std::exception &e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }


        std::cout << "--- Test 6 ---" << std::endl;

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
