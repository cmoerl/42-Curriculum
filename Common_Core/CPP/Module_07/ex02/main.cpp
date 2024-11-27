#include "Array.hpp"

int main() {
    Array<int> arr(5);
    Array<int> arr2(5);

    for (unsigned int i = 0; i < arr.size(); i++) {
        arr[i] = i;
    }
    for (unsigned int i = 0; i < arr2.size(); i++) {
        arr2[i] = i + 5;
    }

    std::cout << arr << std::endl;
    std::cout << arr2 << std::endl;

    arr = arr2;

    std::cout << arr << std::endl;
    std::cout << arr2 << std::endl;

    return (0);
}
