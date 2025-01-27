#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <vector>
#include <list>
#include <string>
#include <stdexcept>
#include <cmath>
#include <climits>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <utility>

class PmergeMe
{
    private:
        std::vector<int>    vec_;
        std::list<int>      lst_;
        double              timeVec_;
        double              timeLst_;

        std::vector<std::vector<int>>   mainChainVec_;
        std::vector<std::vector<int>>   pendingChainVec_;
        std::list<std::list<int>>       mainChainLst_;
        std::list<std::list<int>>       pendingChainLst_;
        size_t                          recursionLevel_;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator = (const PmergeMe &other);
        ~PmergeMe();

        bool    checkInput(const std::string &input) const;
        int     getNextJacNum(int n, int i) const;

        void    initVec(std::string input);
        void    initLst(std::string input);

        void    sortVec();
        void    splitVec();
        void    mergeVec();

        void    sortLst();
        void    splitLst();
        void    mergeLst();

        void    printVec();
        void    printLst();
        void    printTimeVec();
        void    printTimeLst();

};

#endif


/*
Rough draft:

- validate input
- for vector and list:
    - fill container with input numbers
    - print container
    - start timer
    - recursively split container until it has only one element
        - pair up elements
        - make one container with larger numbers, one with smaller numbers
        - keep in mind on which level of recursion which container is
    - recursively merge smaller numbers into larger numbers
        - take smaller number container of level n
        - merge numbers in order of Jacobsthal sequence
        - each smaller number goes left of its pair
        - utilise binary search to find correct position
    - stop timer
- check if merged container is sorted
- print merged container (vector)
- print time for vector
- print time for list
*/