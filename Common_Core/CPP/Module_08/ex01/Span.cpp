#include "Span.hpp"

Span::Span() {
    N_ = 0;
}

Span::Span(unsigned int N) {
    N_ = N;
}

Span::Span(const Span &other) {
    N_ = other.N_;
    numbers_ = other.numbers_;
}

Span &Span::operator = (const Span &other) {
    if (this != &other) {
        N_ = other.N_;
        numbers_ = other.numbers_;
    }
    return (*this);
}

Span::~Span() {}

void    Span::addNumber(int num) {
    if (numbers_.size() < N_)
        numbers_.push_back(num);
    else
        throw std::exception();
}

int     Span::shortestSpan() {
    if (numbers_.size() < 2)
        throw std::exception();
    std::sort(numbers_.begin(), numbers_.end());
    int shortest = std::numeric_limits<int>::max();
    for (std::vector<int>::size_type i = 0; i + 1 < numbers_.size(); i++) {
        int difference = abs(numbers_[i] - numbers_[i + 1]);
        if (difference < shortest)
            shortest = difference;
    }
    return (shortest);
}

int     Span::longestSpan() {
    if (numbers_.size() < 2)
        throw std::exception();
    std::sort(numbers_.begin(), numbers_.end());
    int difference = numbers_.end() - numbers_.begin();
    return (difference);
}

void    Span::addSpecificNumbers(int amount, int number) {
    if (numbers_.size() + amount > N_)
        throw std::exception();
    numbers_.insert(numbers_.end(), amount, number);
}

void Span::addRandomNumbers(int amount, int min, int max) {
    if (numbers_.size() + amount > N_)
        throw std::exception();
    std::srand(std::time(0));
    for (int i = 0; i < amount; ++i) {
        int random = min + std::rand() % (max - min + 1);
        numbers_.push_back(random);
    }
}
