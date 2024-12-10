#include "Span.hpp"
#include <iostream>

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
        throw std::runtime_error("Cannot add more numbers, capacity reached.");
}

int     Span::shortestSpan() {
    if (numbers_.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate the shortest span.");
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
        throw std::runtime_error("Not enough numbers to calculate the longest span.");
    std::sort(numbers_.begin(), numbers_.end());
    int difference = numbers_.back() - numbers_.front();
    return (difference);
}

void    Span::addSpecificNumbers(int amount, int number) {
    if (numbers_.size() + amount > N_)
        throw std::runtime_error("Cannot add more specific numbers, capacity exceeded.");
    numbers_.insert(numbers_.end(), amount, number);
}

void Span::addRandomNumbers(int amount, int min, int max) {
    if (numbers_.size() + amount > N_ || min > max)
        throw std::runtime_error("Cannot add more random numbers, capacity exceeded or invalid range.");
    std::srand(std::time(0));
    for (int i = 0; i < amount; ++i) {
        int random = min + std::rand() % (max - min + 1);
        numbers_.push_back(random);
    }
}

void Span::printNumbers() const {
    std::cout << "content: ";
    for (std::vector<int>::const_iterator it = this->numbers_.begin(); it != this->numbers_.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
