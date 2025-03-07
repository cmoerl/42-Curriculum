#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./pmergeMe [input]" << std::endl;
        return 1;
    }

    try {
        PmergeMe pmergeMe;
        std::cout << "Before: ";
        std::cout << argv[1] << std::endl;

        double startVec = static_cast<double>(clock());
        pmergeMe.initVec(argv[1]);
        pmergeMe.sortVec();
        double endVec = static_cast<double>(clock());

        // double startLst = static_cast<double>(clock());
        // pmergeMe.initLst(argv[1]);
        // pmergeMe.sortLst();
        // double endLst = static_cast<double>(clock());

        pmergeMe.timeVec = (endVec - startVec) / CLOCKS_PER_SEC * 1000000;
        // pmergeMe.timeLst = (endLst - startLst) / CLOCKS_PER_SEC * 1000000;

        // if (!pmergeMe.checkResult())
        //     throw std::runtime_error("Error: result containers are not sorted");

        std::cout << "After: ";
        pmergeMe.printVec();
        pmergeMe.printTimeVec();
        // pmergeMe.printTimeLst();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
