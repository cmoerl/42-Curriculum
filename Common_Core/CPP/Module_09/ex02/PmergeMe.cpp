#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator = (const PmergeMe &other) {
    if (this != &other) {
        vec_ = other.vec_;
        lst_ = other.lst_;
        timeVec_ = other.timeVec_;
        timeLst_ = other.timeLst_;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool    PmergeMe::checkInput(const std::string &input) const {
    if (input.empty() || input.size() < 3)
        throw std::invalid_argument("Input is empty or too short");

    size_t i = 0;
    int numbers = 0;

    while (i < input.length()) {
        if (isdigit(input[i])) {
            numbers++;
            while (isdigit(input[i]))
                i++;
        } else if (input[i] == ' ')
            i++;
        else
            throw std::invalid_argument("Invalid character in input");
    }

    return (true);
}

int     PmergeMe::getNextJacNum(int n, int i) const {
    if (n == 0 && i == 1)
        return (1);
    return (std::pow(2, i + 1) - n);
}

void    PmergeMe::initVec(std::string input) {
    std::vector<int> vec;
    std::istringstream ss(input);
    std::string token;

    while (ss >> token) {
        char *endptr;
        errno = 0;
        long value = strtol(token.c_str(), &endptr, 10);
        
        if (errno == ERANGE || value > INT_MAX || value < 0)
            throw std::invalid_argument("Error: number out of range");
            
        vec.push_back(static_cast<int>(value));
    }
    vec_ = vec;
}

void    PmergeMe::initLst(std::string input) {
    std::list<int> lst;
    std::istringstream ss(input);
    std::string token;

    while (ss >> token) {
        char *endptr;
        errno = 0;
        long value = strtol(token.c_str(), &endptr, 10);
        
        if (errno == ERANGE || value > INT_MAX || value < 0)
            throw std::invalid_argument("Error: number out of range");
            
        lst.push_back(static_cast<int>(value));
    }
    lst_ = lst;
}

void    splitVec() {
// - recursively split container until it has only one element
    // - pair up elements
    // - make one container with larger numbers, one with smaller numbers
    // - keep in mind on which level of recursion which container is
}

void    mergeVec() {
// - recursively merge smaller numbers into larger numbers
    // - take smaller number container of level n
    // - merge numbers in order of Jacobsthal sequence
    // - each smaller number goes left of its pair
    // - utilise binary search to find correct position
}

void    PmergeMe::sortVec() {
    double start = static_cast<double>(clock());
    splitVec();
    mergeVec();
    double end = static_cast<double>(clock());
    timeVec_ = (end - start) / CLOCKS_PER_SEC * 1000000;
}

void    splitLst() {
// - recursively split container until it has only one element
    // - pair up elements
    // - make one container with larger numbers, one with smaller numbers
    // - keep in mind on which level of recursion which container is
}

void    mergeLst() {
// - recursively merge smaller numbers into larger numbers
    // - take smaller number container of level n
    // - merge numbers in order of Jacobsthal sequence
    // - each smaller number goes left of its pair
    // - utilise binary search to find correct position
}

void    PmergeMe::sortLst() {
    double start = static_cast<double>(clock());
    splitLst();
    mergeLst();
    double end = static_cast<double>(clock());
    timeLst_ = (end - start) / CLOCKS_PER_SEC * 1000000;
}

void    PmergeMe::printVec() {
    for (size_t i = 0; i < vec_.size(); i++) {
        std::cout << vec_[i];
        if (i != vec_.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::printLst() {
    for (std::list<int>::iterator it = lst_.begin(); it != lst_.end(); it++) {
        std::cout << *it;
        if (it != --lst_.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::printTimeVec() {
    std::cout << "Time to process a range of " << vec_.size() << " elements with std::vector : " << timeVec_ << " us" << std::endl;
}

void    PmergeMe::printTimeLst() {
    std::cout << "Time to process a range of " << lst_.size() << " elements with std::list : " << timeLst_ << " us" << std::endl;
}

