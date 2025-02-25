#include "PmergeMe.hpp"

int main() {
    PmergeMe    pmm;

/*     std::cout << "Vector:" << std::endl;

    try {
        pmm.initVec("8 9 10 11 12 13 14 15 1 2 3 4 5 6 7");
        std::cout << "Before: ";
        pmm.printVec();
        pmm.sortVec();
        std::cout << "After: ";
        pmm.printVec();
        pmm.printTimeVec();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        pmm.initVec("1 2 3");
        std::cout << "Before: ";
        pmm.printVec();
        pmm.sortVec();
        std::cout << "After: ";
        pmm.printVec();
        pmm.printTimeVec();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        pmm.initVec("-1");
        std::cout << "Before: ";
        pmm.printVec();
        pmm.sortVec();
        std::cout << "After: ";
        pmm.printVec();
        pmm.printTimeVec();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        pmm.initVec("");
        std::cout << "Before: ";
        pmm.printVec();
        pmm.sortVec();
        std::cout << "After: ";
        pmm.printVec();
        pmm.printTimeVec();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        pmm.initVec("100 7 42 45");
        std::cout << "Before: ";
        pmm.printVec();
        pmm.sortVec();
        std::cout << "After: ";
        pmm.printVec();
        pmm.printTimeVec();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        pmm.initVec("100 7 42 45 100");
        std::cout << "Before: ";
        pmm.printVec();
        pmm.sortVec();
        std::cout << "After: ";
        pmm.printVec();
        pmm.printTimeVec();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        pmm.initVec("1 1 1 1");
        std::cout << "Before: ";
        pmm.printVec();
        pmm.sortVec();
        std::cout << "After: ";
        pmm.printVec();
        pmm.printTimeVec();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    } */

    std::cout << std::endl << "List:" << std::endl;

    try {
        pmm.initLst("8 9 10 11 12 13 14 15 1 2 3 4 5 6 7");
        std::cout << "Before: ";
        pmm.printLst();
        pmm.sortLst();
        std::cout << "After: ";
        pmm.printLst();
        pmm.printTimeLst();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        pmm.initLst("1 2 3");
        std::cout << "Before: ";
        pmm.printLst();
        pmm.sortLst();
        std::cout << "After: ";
        pmm.printLst();
        pmm.printTimeLst();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        pmm.initLst("-1");
        std::cout << "Before: ";
        pmm.printLst();
        pmm.sortLst();
        std::cout << "After: ";
        pmm.printLst();
        pmm.printTimeLst();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        pmm.initLst("");
        std::cout << "Before: ";
        pmm.printLst();
        pmm.sortLst();
        std::cout << "After: ";
        pmm.printLst();
        pmm.printTimeLst();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        pmm.initLst("100 7 42 45");
        std::cout << "Before: ";
        pmm.printLst();
        pmm.sortLst();
        std::cout << "After: ";
        pmm.printLst();
        pmm.printTimeLst();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        pmm.initLst("100 7 42 45 100");
        std::cout << "Before: ";
        pmm.printLst();
        pmm.sortLst();
        std::cout << "After: ";
        pmm.printLst();
        pmm.printTimeLst();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        pmm.initLst("1 1 1 1");
        std::cout << "Before: ";
        pmm.printLst();
        pmm.sortLst();
        std::cout << "After: ";
        pmm.printLst();
        pmm.printTimeLst();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    } 

    return 0;
}
