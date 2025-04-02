#include "PmergeMe.hpp"
#include <cstddef>

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
    if (input.empty())
        throw std::invalid_argument("Error: Input cannot be empty");

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
            throw std::invalid_argument("Error: Invalid character in input");
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
    std::vector< std::pair<int, int> >& currentChain = mainChainVec_[recursionLevel_];
    if (currentChain.size() <= 1) {
        lowestLevel_ = true;
        return;
    }
        
    std::vector< std::pair<int, int> > mainChain; // first - value, second - index
    std::vector< std::pair<int, int> > pendingChain;
    std::vector< std::pair<int, int> > pairs; // first - main index, second - pending index
    
    for (size_t i = 0; i < currentChain.size() - 1; i += 2) {
        if (currentChain[i] > currentChain[i + 1]) {
            pairs.push_back(std::make_pair(currentChain[i].second, currentChain[i + 1].second));
            mainChain.push_back(currentChain[i]);
            pendingChain.push_back(currentChain[i + 1]);
        } else {
            pairs.push_back(std::make_pair(currentChain[i + 1].second, currentChain[i].second));
            mainChain.push_back(currentChain[i + 1]);
            pendingChain.push_back(currentChain[i]);
        }
    }
    
    if (currentChain.size() % 2) {
        pairs.push_back(std::make_pair(-1, currentChain.size() - 1));
        pendingChain.push_back(currentChain.back());
    }
        
    mainChainVec_.push_back(mainChain);
    pendingChainVec_.push_back(pendingChain);
    pairsVec_.push_back(pairs);
    
    recursionLevel_++;
    splitVec();
}

int binarySearchVec(std::pair<int, int> toSort, std::vector< std::pair<int, int> > vec, int value) {
    int left = 0;
    int right = toSort.first - 1;
    if (toSort.first == -1)
        right = vec.size() - 1;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (vec[mid].first == value)
            return mid;
        if (vec[mid].first < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

void updateToSortVec(std::vector<std::pair<int, int> > &pairs, std::vector< std::pair<int, int> > &sorted,
                         std::vector< std::pair<int, int> > &toSort, std::vector< std::pair<int, int> > &pendingChain) {
    for (size_t i = 0; i < toSort.size(); i++) {
        int pendingIndex = pendingChain[toSort[i].second].second;
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].second == pendingIndex) {
                int mainIndex = pairs[j].first;
                for (size_t k = 0; k < sorted.size(); k++) {
                    if (sorted[k].second == mainIndex) {
                        toSort[i].first = k;
                        break;
                    }
                }
                break;
            }
        }
    }
}

void    PmergeMe::mergeVec() {
    if (recursionLevel_ == 0) {
        if (!lowestLevel_ && mainChainVec_.size() > 1) {
            mainChainVec_[0] = mainChainVec_[1];
        }
        return;
    }
    
    std::vector< std::pair<int, int> >&     mainChain = mainChainVec_[recursionLevel_];
    std::vector< std::pair<int, int> >&     pendingChain = pendingChainVec_[recursionLevel_ - 1];
    std::vector< std::pair<int, int> >&     pairs = pairsVec_[recursionLevel_ - 1]; // first - main index, second - pending index
    std::vector< std::pair<int, int> >      toSort;

    size_t jacNum = 0;
    for (size_t i = 0; i < mainChain.size() || i < pendingChain.size(); i++) {
        jacNum = getNextJacNum(jacNum, pendingChain.size());
        if (jacNum == mainChain.size() + 1)
            toSort.push_back(std::make_pair(-1, jacNum - 1));
        else
            toSort.push_back(std::make_pair(jacNum - 1, jacNum - 1));
    }

    if (!lowestLevel_) {
        updateToSortVec(pairs, mainChainVec_[recursionLevel_ + 1], toSort, pendingChain);
        mainChain = mainChainVec_[recursionLevel_ + 1];
    }

    size_t i = 0;
    while (i < toSort.size()) {
        int index = binarySearchVec(toSort[i], mainChain, pendingChain[toSort[i].second].first);
        mainChain.insert(mainChain.begin() + index, pendingChain[toSort[i].second]);
        for (size_t j = 0; j < toSort.size(); j++) {
            if (toSort[j].first >= index)
                toSort[j].first++;
        }
        i++;
    }

    lowestLevel_ = false;
    recursionLevel_--;
    mergeVec();
}

void    PmergeMe::sortVec() {
    recursionLevel_ = 0;
    mainChainVec_.clear();
    pendingChainVec_.clear();
    pairsVec_.clear();

    mainChainVec_.push_back(std::vector< std::pair<int, int> >());
    for (size_t i = 0; i < vec_.size(); i++)
        mainChainVec_[0].push_back(std::make_pair(vec_[i], i));

    splitVec();
    mergeVec();

    for (size_t i = 0; i < mainChainVec_[0].size(); i++)
        vec_[i] = mainChainVec_[0][i].first;

    if (recursionLevel_ > 0)
        throw std::runtime_error("Error: recursion level not zero after merge");
}

void PmergeMe::splitLst() {
    std::list< std::pair<int, int> >& currentChain = mainChainLst_.back();
    if (currentChain.size() <= 1) {
        lowestLevel_ = true;
        return;
    }

    std::list< std::pair<int, int> > mainChain;
    std::list< std::pair<int, int> > pendingChain;
    std::list< std::pair<int, int> > pairs; // first - main index, second - pending index

    std::list< std::pair<int, int> >::iterator it = currentChain.begin();
    int i = 0;
    while (it != currentChain.end()) {
        std::pair<int, int> first = *it;
        ++it;
        if (it != currentChain.end()) {
            std::pair<int, int> second = *it;
            if (first.first > second.first) {
                pairs.push_back(std::make_pair(first.second, second.second));
                mainChain.push_back(first);
                pendingChain.push_back(second);
            } else {
                pairs.push_back(std::make_pair(second.second, first.second));
                mainChain.push_back(second);
                pendingChain.push_back(first);
            }
            ++it;
        } else {
            pairs.push_back(std::make_pair(-1, currentChain.size() - 1));
            pendingChain.push_back(first);
        }
        i += 2;
    }

    mainChainLst_.push_back(mainChain);
    pendingChainLst_.push_back(pendingChain);
    pairsLst_.push_back(pairs);

    recursionLevel_++;
    splitLst();
}

void updateToSortLst(std::list<std::pair<int, int> > &pairs, std::list< std::pair<int, int> > &sorted, 
                     std::vector< std::pair<int, int> > &toSort, std::list< std::pair<int, int> > &pendingChain) {
    for (size_t i = 0; i < toSort.size(); i++) {
        std::list < std::pair<int, int> >::iterator pendingIt = pendingChain.begin();
        std::advance(pendingIt, toSort[i].second);
        int pendingIndex = pendingIt->second;
        for (std::list< std::pair<int, int> >::iterator pairsIt = pairs.begin(); pairsIt != pairs.end(); ++pairsIt) {
            if (pairsIt->second == pendingIndex) {
                int mainIndex = pairsIt->first;
                std::list< std::pair<int, int> >::iterator sortedIt = sorted.begin();
                for (size_t j = 0; j < sorted.size(); j++, ++sortedIt) {
                    if (sortedIt->second == mainIndex) {
                        toSort[i].first = j;
                        break;
                    }
                }
                break;
            }
        }
    }
}

int binarySearchLst(std::pair<int, int> toSort, std::list< std::pair<int, int> > lst, int value) {
    int left = 0;
    int right = toSort.first - 1;
    if (toSort.first == -1)
        right = lst.size() - 1;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        std::list< std::pair<int, int> >::iterator it = lst.begin();
        std::advance(it, mid);
        if (it->first == value)
            return mid;
        if (it->first < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

void PmergeMe::mergeLst() {
    if (recursionLevel_ == 0) {
        if (!lowestLevel_ && mainChainLst_.size() > 1) {
            std::list< std::list< std::pair<int, int> > >::iterator it = mainChainLst_.begin();
            std::list< std::list< std::pair<int, int> > >::iterator next = it;
            ++next;
            mainChainLst_.splice(it, mainChainLst_, next);
        }
        return;
    }

    std::list< std::list< std::pair<int, int> > >::iterator mainIt = mainChainLst_.begin();
    std::advance(mainIt, recursionLevel_);
    std::list< std::pair<int, int> >& mainChain = *mainIt;

    std::list< std::list< std::pair<int, int> > >::iterator pendingIt = pendingChainLst_.begin();
    std::advance(pendingIt, recursionLevel_ - 1);
    std::list< std::pair <int, int> >& pendingChain = *pendingIt;

    std::list< std::list< std::pair<int, int> > >::iterator pairsIt = pairsLst_.begin();
    std::advance(pairsIt, recursionLevel_ - 1); 
    std::list< std::pair<int, int> >& pairs = *pairsIt;

    std::vector < std::pair<int, int> > toSort;

    size_t jacNum = 0;
    for (size_t i = 0; i < mainChain.size() || i < pendingChain.size(); i++) {
        jacNum = getNextJacNum(jacNum, pendingChain.size());
        if (jacNum == mainChain.size() + 1)
            toSort.push_back(std::make_pair(-1, jacNum - 1));
        else
            toSort.push_back(std::make_pair(jacNum - 1, jacNum - 1));
    }

    if (!lowestLevel_) {
        std::list< std::list< std::pair<int, int> > >::iterator it = mainChainLst_.begin();
        std::advance(it, recursionLevel_ + 1);
        std::list< std::pair<int, int> >& nextMainChain = *it;
        updateToSortLst(pairs, nextMainChain, toSort, pendingChain);
        mainChain = nextMainChain;
    }

    size_t i = 0;
    while (i < toSort.size()) {
        std::list< std::pair<int, int> >::iterator it = pendingChain.begin();
        std::advance(it, toSort[i].second);
        int index = binarySearchLst(toSort[i], mainChain, it->first);
        std::list< std::pair<int, int> >::iterator insertIt = mainChain.begin();
        std::advance(insertIt, index);
        mainChain.insert(insertIt, *it);
        for (size_t j = 0; j < toSort.size(); j++) {
            if (toSort[j].first >= index)
                toSort[j].first++;
        }
        i++;
    }

    lowestLevel_ = false;
    recursionLevel_--;
    mergeLst();
}

void PmergeMe::sortLst() {
    recursionLevel_ = 0;
    mainChainLst_.clear();
    pendingChainLst_.clear();
    pairsLst_.clear();

    mainChainLst_.push_back(std::list< std::pair<int, int> >());
    size_t i = 0;
    for (std::list<int>::iterator it = lst_.begin(); it != lst_.end(); it++) {
        mainChainLst_.back().push_back(std::make_pair(*it, i));
        i++;
    }

    splitLst();
    mergeLst();

    std::list< std::pair<int, int> >& sortedLst = mainChainLst_.front();
    std::list< std::pair<int, int> >::iterator it = sortedLst.begin();
    std::list<int>::iterator lstIt = lst_.begin();
    while (it != sortedLst.end() && lstIt != lst_.end()) {
        *lstIt = it->first;
        ++it;
        ++lstIt;
    }
    
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
