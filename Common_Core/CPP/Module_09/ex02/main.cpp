#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./pmergeMe [input]" << std::endl;
        return 1;
    }

    try {
        PmergeMe pmergeMe;
        pmergeMe.initVec(argv[1]);
        pmergeMe.initLst(argv[1]);
        std::cout << "Before: ";
        pmergeMe.printVec();
        pmergeMe.sortVec();
        pmergeMe.sortLst();
        std::cout << "After: ";
        pmergeMe.printVec();
        pmergeMe.printTimeVec();
        pmergeMe.printTimeLst();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
