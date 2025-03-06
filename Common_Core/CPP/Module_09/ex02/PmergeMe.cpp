#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator = (const PmergeMe &other) {
    if (this != &other) {
        vec_ = other.vec_;
        lst_ = other.lst_;
        timeVec = other.timeVec;
        timeLst = other.timeLst;
        mainChainVec_ = other.mainChainVec_;
        pendingChainVec_ = other.pendingChainVec_;
        mainChainLst_ = other.mainChainLst_;
        pendingChainLst_ = other.pendingChainLst_;
        recursionLevel_ = other.recursionLevel_;
        lowestLevel_ = other.lowestLevel_;
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
    if (current == 1) {
        if (size == 2)
            return 2;
        return 3;
    }
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
    if (it != jacobs.end() && (it + 2) != jacobs.end()) {
        return *(it + 2);
    } else if (it != jacobs.end() && (it + 2) == jacobs.end()) {
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

/* potential solution for index saving:

void    PmergeMe::splitVec() {
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
        
    std::vector< std::pair <int, int> > mainChain;
    std::vector< std::pair <int, int> > pendingChain;
    
    for (size_t i = 0; i < currentChain.size() - 1; i += 2) {
        if (currentChain[i] > currentChain[i + 1]) {
            mainChain.push_back(std::make_pair(currentChain[i], i));
            pendingChain.push_back(std::make_pair(currentChain[i + 1], i + 1));
        } else {
            mainChain.push_back(std::make_pair(currentChain[i + 1], i));
            pendingChain.push_back(std::make_pair(currentChain[i], i + 1));
        }
    }
    
    if (currentChain.size() % 2)
        pendingChain.push_back(std::make_pair(currentChain.back(), currentChain.size() - 1));

    std::vector <int> mainVec;
    std::vector <int> pendingVec;
        
    mainChainVec_.push_back(std::move(mainVec));
    pendingChainVec_.push_back(std::move(pendingVec));
    
    recursionLevel_++;
    splitVec();
} */

int binarySearchVec(std::pair<int, int> pair, std::vector<int> vec, int value) {
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

void updatePairsVec(std::vector<std::pair<int, int> > &pairs, std::vector<int> &current, std::vector<int> &sorted) {
    for (size_t i = 0; i < pairs.size(); i++) {
        if (pairs[i].first == -1)
            continue;
            
        std::vector<int>::iterator it = std::find(sorted.begin(), sorted.end(), current[pairs[i].first]);
        if (it != sorted.end())
            pairs[i].first = std::distance(sorted.begin(), it);
    }
}

void    PmergeMe::mergeVec() {
    if (recursionLevel_ == 0) {
        if (!lowestLevel_)
            mainChainVec_[0] = mainChainVec_[1];
        return;
    }
    
    std::vector<int>& mainChain = mainChainVec_[recursionLevel_];
    std::vector<int>& pendingChain = pendingChainVec_[recursionLevel_ - 1];
    std::vector< std::pair<int, int> >    pairs; // first - main index, second - pending index

    size_t jacNum = 0;
    for (size_t i = 0; i < mainChain.size() || i < pendingChain.size(); i++) {
        jacNum = getNextJacNum(jacNum, pendingChain.size());
        if (jacNum == mainChain.size())
            pairs.push_back(std::make_pair(-1, jacNum - 1));
        else
            pairs.push_back(std::make_pair(jacNum - 1, jacNum - 1));
    }

    if (!lowestLevel_) {
        updatePairsVec(pairs, mainChainVec_[recursionLevel_], mainChainVec_[recursionLevel_ + 1]);
        mainChain = mainChainVec_[recursionLevel_ + 1];
    }

    size_t i = 0;
    while (i < pairs.size()) {
        int index = binarySearchVec(pairs[i], mainChain, pendingChain[pairs[i].second]);
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
    recursionLevel_ = 0;
    splitVec();
    mergeVec();
    vec_ = mainChainVec_[0];

    if (recursionLevel_ > 0)
        throw std::runtime_error("Error: recursion level not zero after merge");
}

void PmergeMe::splitLst() {
    if (recursionLevel_ == 0) {
        mainChainLst_.clear();
        pendingChainLst_.clear();
        mainChainLst_.push_back(lst_);
    }

    std::list<int>& currentChain = mainChainLst_.back();
    if (currentChain.size() <= 1) {
        lowestLevel_ = true;
        return;
    }

    std::list<int> mainChain;
    std::list<int> pendingChain;

    std::list<int>::iterator it = currentChain.begin();
    while (it != currentChain.end()) {
        int first = *it;
        ++it;
        if (it != currentChain.end()) {
            int second = *it;
            if (first > second) {
                mainChain.push_back(first);
                pendingChain.push_back(second);
            } else {
                mainChain.push_back(second);
                pendingChain.push_back(first);
            }
            ++it;
        } else {
            pendingChain.push_back(first);
        }
    }

    mainChainLst_.push_back(mainChain);
    pendingChainLst_.push_back(pendingChain);

    recursionLevel_++;
    splitLst();
}

void updatePairsLst(std::vector<std::pair<int, int> > &pairs, std::list<int> &current, std::list<int> &sorted) {
    for (size_t i = 0; i < pairs.size(); i++) {
        if (pairs[i].first == -1)
            continue;
            
        std::list<int>::iterator itCurrent = current.begin();
        std::advance(itCurrent, pairs[i].first);
        std::list<int>::iterator itSorted = std::find(sorted.begin(), sorted.end(), *itCurrent);
        if (itSorted != sorted.end())
            pairs[i].first = std::distance(sorted.begin(), itSorted);
    }
}

int binarySearchLst(std::pair<int, int> pair, std::list<int> &lst, int value) {
    int left = 0;
    int right = pair.first - 1;
    if (pair.first == -1)
        right = lst.size() - 1;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        std::list<int>::iterator it = lst.begin();
        std::advance(it, mid);
        if (*it == value)
            return mid;
        if (*it < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

void PmergeMe::mergeLst() {
    if (recursionLevel_ == 0) {
        if (!lowestLevel_ && mainChainLst_.size() > 1) {
            std::list<std::list<int> >::iterator it = mainChainLst_.begin();
            std::list<std::list<int> >::iterator next = it;
            ++next;
            mainChainLst_.splice(it, mainChainLst_, next);
        }
        return;
    }

    std::list<std::list<int> >::iterator mainIt = mainChainLst_.begin();
    std::advance(mainIt, recursionLevel_);
    std::list<int>& mainChain = *mainIt;

    std::list<std::list<int> >::iterator pendingIt = pendingChainLst_.begin();
    std::advance(pendingIt, recursionLevel_ - 1);
    std::list<int>& pendingChain = *pendingIt;

    std::vector<std::pair<int, int> > pairs; // first - main index, second - pending index

    size_t jacNum = 0;
    for (size_t i = 0; i < mainChain.size() || i < pendingChain.size(); i++) {
        jacNum = getNextJacNum(jacNum, pendingChain.size());
        if (jacNum == mainChain.size() + 1)
            pairs.push_back(std::make_pair(-1, jacNum - 1));
        else
            pairs.push_back(std::make_pair(jacNum - 1, jacNum - 1));
    }

    if (!lowestLevel_) {
        std::list<std::list<int> >::iterator it = mainChainLst_.begin();
        std::advance(it, recursionLevel_ + 1);
        std::list<int>& nextMainChain = *it;
        updatePairsLst(pairs, mainChain, nextMainChain);
        mainChain = nextMainChain;
    }

    size_t i = 0;
    while (i < pairs.size()) {
        std::list<int>::iterator it = pendingChain.begin();
        std::advance(it, pairs[i].second);
        int index = binarySearchLst(pairs[i], mainChain, *it);
        std::list<int>::iterator insertIt = mainChain.begin();
        std::advance(insertIt, index);
        mainChain.insert(insertIt, *it);
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].first >= index)
                pairs[j].first++;
        }
        i++;
    }

    lowestLevel_ = false;
    recursionLevel_--;
    mergeLst();
}

void PmergeMe::sortLst() {
    recursionLevel_ = 0;
    splitLst();
    mergeLst();
    lst_ = mainChainLst_.front();
    
    if (recursionLevel_ > 0)
        throw std::runtime_error("Error: recursion level not zero after merge");
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
    std::cout << "Time to process a range of " << vec_.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
}

void    PmergeMe::printTimeLst() {
    std::cout << "Time to process a range of " << lst_.size() << " elements with std::list : " << timeLst << " us" << std::endl;
}

bool    PmergeMe::checkResult() const {
    for (size_t i = 0; i < vec_.size() - 1; i++) {
        if (vec_[i] > vec_[i + 1])
            return false;
    }
    for (size_t i = 0; i < lst_.size() - 1; i++) {
        std::list<int>::const_iterator it = lst_.begin();
        std::advance(it, i);
        std::list<int>::const_iterator next = it;
        ++next;
        if (*it > *next)
            return false;
    }
    return true;
}
