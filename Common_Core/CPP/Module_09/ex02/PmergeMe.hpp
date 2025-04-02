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
#include <cerrno>

class PmergeMe
{
    private:
        std::vector<int>    vec_;
        std::list<int>      lst_;

        std::vector< std::vector< std::pair<int, int> > >       mainChainVec_;
        std::vector< std::vector< std::pair<int, int> > >       pendingChainVec_;
        std::list< std::list< std::pair<int, int> > >           mainChainLst_;
        std::list< std::list< std::pair<int, int> > >           pendingChainLst_;
        std::vector< std::vector< std::pair<int, int> > >       pairsVec_;
        std::list< std::list< std::pair<int, int> > >           pairsLst_;
        size_t                                                  recursionLevel_;
        bool                                                    lowestLevel_;

        int     getNextJacNum(int n, int i) const;

        void    splitVec();
        void    mergeVec();

        void    splitLst();
        void    mergeLst();

    public:
        double              timeVec;
        double              timeLst;

        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator = (const PmergeMe &other);
        ~PmergeMe();

        void    initVec(std::string input);
        void    initLst(std::string input);

        void    sortVec();
        void    sortLst();

        void    printVec();
        void    printLst();
        void    printTimeVec();
        void    printTimeLst();

        bool    checkInput(const std::string &input) const;
        bool    checkResult() const;

};

#endif


/*
Rough draft:

- validate input
- for vector and list:
    - start timer
    - fill container with input numbers
    - print container
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
