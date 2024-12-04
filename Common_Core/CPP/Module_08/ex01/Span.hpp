#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <limits>

class   Span
{
    private:
        std::vector<int>    numbers_;
        unsigned int        N_;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator = (const Span &other);
        ~Span();

        void    addNumber(int num);
        int     shortestSpan();
        int     longestSpan();

        void    addSpecificNumbers(int amount, int numbers);
        void    addRandomNumbers(int amount, int min, int max);

};

#endif
