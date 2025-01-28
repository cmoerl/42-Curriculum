#include "PmergeMe.hpp"

int main() {
    PmergeMe    pmm;

    pmm.initVec("8 9 10 11 12 13 14 15 1 2 3 4 5 6 7");
    pmm.sortVec();
    pmm.printVec();
    // pmm.printTimeVec();

    return 0;
}
