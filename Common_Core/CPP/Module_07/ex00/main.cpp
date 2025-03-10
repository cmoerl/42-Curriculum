#include "whatever.hpp"
#include <string>
#include <iostream>

int main() {
    int num1 = 10;
    int num2 = 30;

    std::string str1 = "Hello";
    std::string str2 = "World!";

    std::cout << "num1: " << num1 << ", num2: " << num2 << std::endl;
    std::cout << "str1: " << str1 << ", str2: " << str2 << std::endl;

    ::swap(num1, num2);
    ::swap(str1, str2);

    std::cout << "num1: " << num1 << ", num2: " << num2 << std::endl;
    std::cout << "str1: " << str1 << ", str2: " << str2 << std::endl;

    std::cout << ::min(num1, num2) << std::endl;
    std::cout << ::max(num1, num2) << std::endl;

    std::cout << ::min(str1, str2) << std::endl;
    std::cout << ::max(str1, str2) << std::endl;

    float num3 = 10.5f;
    float num4 = 30.5f;

    std::cout << "num3: " << num3 << ", num4: " << num4 << std::endl;

    ::swap(num3, num4);

    std::cout << "num3: " << num3 << ", num4: " << num4 << std::endl;

    std::cout << ::min(num3, num4) << std::endl;
    std::cout << ::max(num3, num4) << std::endl;

    return (0);
}
