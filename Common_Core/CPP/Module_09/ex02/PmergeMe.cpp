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
        mainChainVec_ = other.mainChainVec_;
        pendingChainVec_ = other.pendingChainVec_;
        mainChainLst_ = other.mainChainLst_;
        pendingChainLst_ = other.pendingChainLst_;
        recursionLevel_ = other.recursionLevel_;
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

int     PmergeMe::getNextJacNum(int current, int size) const {
    if (current == 0)
        return 1;
    if (current == 1)
        return 3;
    int j = 1;
    int i = 1;
    std::vector<int> jacobs;
    while (j <= size) {
        jacobs.push_back(j);
        j = pow(2, i + 1) - j;
        i++;
    }
    std::vector<int>::iterator it;
    it = std::find(jacobs.begin(), jacobs.end(), current - 1);
    if (it != jacobs.end() && (it + 1) != jacobs.end()) {
        return *(it + 2);
    } else if (it != jacobs.end() && (it + 1) == jacobs.end()) {
        return (size);
    } else {
        return (current - 1);
    }
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

void    PmergeMe::splitVec() {
    std::cout << "recursionLevel_ = " << recursionLevel_ << std::endl;
    if (recursionLevel_ == 0) {
        mainChainVec_.clear();
        pendingChainVec_.clear();
        mainChainVec_.push_back(vec_);
    }
    
    std::vector<int>& currentChain = mainChainVec_[recursionLevel_];
    if (currentChain.size() <= 1) {
        lowestLevel_ = true;
        return;
    }
        
    std::vector<int> mainChain;
    std::vector<int> pendingChain;
    
    for (size_t i = 0; i < currentChain.size() - 1; i += 2) {
        if (currentChain[i] > currentChain[i + 1]) {
            mainChain.push_back(currentChain[i]);
            pendingChain.push_back(currentChain[i + 1]);
        } else {
            mainChain.push_back(currentChain[i + 1]);
            pendingChain.push_back(currentChain[i]);
        }
    }
    
    if (currentChain.size() % 2)
        pendingChain.push_back(currentChain.back());
        
    mainChainVec_.push_back(mainChain);
    pendingChainVec_.push_back(pendingChain);
    
    recursionLevel_++;
    splitVec();
}

int binarySearch(std::pair<int, int> pair, std::vector<int> vec, int value) {
    int left = 0;
    int right = pair.first - 1;
    if (pair.first == -1)
        right = vec.size() - 1;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (vec[mid] == value)
            return mid;
        if (vec[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

void updatePairs(std::vector<std::pair<int, int> > &pairs, std::vector<int> &current, std::vector<int> &sorted) {
    for (size_t i = 0; i < pairs.size(); i++) {
        if (pairs[i].first == -1)
            continue;
            
        std::vector<int>::iterator it = std::find(sorted.begin(), sorted.end(), current[pairs[i].first]);
        if (it != sorted.end())
            pairs[i].first = std::distance(sorted.begin(), it);
    }
}

// final vector is not sorted fully, I believe the cause is leaving recursion too early
void    PmergeMe::mergeVec() {
    std::cout << "recursionLevel_ = " << recursionLevel_ << std::endl;
    if (recursionLevel_ == 0)
        return;
    
    std::vector<int>& mainChain = mainChainVec_[recursionLevel_];
    std::vector<int>& pendingChain = pendingChainVec_[recursionLevel_ - 1];
    std::vector< std::pair<int, int> >    pairs; // first - main index, second - pending index

    int jacNum = 0;
    for (size_t i = 0; i < mainChain.size(); i++) {
        jacNum = getNextJacNum(jacNum, mainChain.size());
        pairs.push_back(std::make_pair(jacNum -1, jacNum - 1));
    }
    if (pairs.size() % 2)
        pairs.push_back(std::make_pair(-1, pairs.size()));

    if (!lowestLevel_) {
        updatePairs(pairs, mainChainVec_[recursionLevel_], mainChainVec_[recursionLevel_ + 1]);
        mainChain = mainChainVec_[recursionLevel_ + 1];
    }

    size_t i = 0;
    while (i < pairs.size()) {
        int index = binarySearch(pairs[i], mainChain, pendingChain[pairs[i].second]);
        mainChain.insert(mainChain.begin() + index, pendingChain[pairs[i].second]);
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].first >= index)
                pairs[j].first++;
        }
        i++;
    }

    lowestLevel_ = false;
    recursionLevel_--;
    mergeVec();
}

void    PmergeMe::sortVec() {
    double start = static_cast<double>(clock());
    recursionLevel_ = 0;
    splitVec();
    mergeVec();
    vec_ = mainChainVec_[0];
    if (recursionLevel_ > 0)
        throw std::runtime_error("Error: recursion level not zero after merge");
    double end = static_cast<double>(clock());
    timeVec_ = (end - start) / CLOCKS_PER_SEC * 1000000;
}

/* void    PmergeMe::splitLst() {
// - recursively split container until it has only one element
    // - pair up elements
    // - make one container with larger numbers, one with smaller numbers
    // - keep in mind on which level of recursion which container is
} */

/* void    PmergeMe::mergeLst() {
// - recursively merge smaller numbers into larger numbers
    // - take smaller number container of level n
    // - merge numbers in order of Jacobsthal sequence
    // - each smaller number goes left of its pair
    // - utilise binary search to find correct position
} */

/* void    PmergeMe::sortLst() {
    double start = static_cast<double>(clock());
    splitLst();
    mergeLst();
    double end = static_cast<double>(clock());
    timeLst_ = (end - start) / CLOCKS_PER_SEC * 1000000;
} */

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

