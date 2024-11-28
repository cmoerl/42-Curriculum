#include "../inc/Array.hpp"

int main() {
    Array<int> arr(5);
    Array<int> arr2(5);
    Array<char> arr3(5);

    std::cout << "Initial arrays:" << std::endl;
    std::cout << arr << std::endl;

    try {
        for (unsigned int i = 0; i < arr.size(); i++) {
            arr[i] = i;
        }
        for (unsigned int i = 0; i < arr2.size(); i++) {
            arr2[i] = i + 5;
        }
        for (unsigned int i = 0; i < arr3.size(); i++) {
            arr3[i] = i + 65;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Arrays after initialization:" << std::endl;
    std::cout << arr << std::endl;
    std::cout << arr2 << std::endl;
    std::cout << arr3 << std::endl;

    arr = arr2;

    std::cout << "Arrays after assignment:" << std::endl;
    std::cout << arr << std::endl;
    std::cout << arr2 << std::endl;

    // Test the copy constructor
    Array<int> arrCopy(arr);
    std::cout << "Array after copy construction:" << std::endl;
    std::cout << arrCopy << std::endl;

    return (0);
}
