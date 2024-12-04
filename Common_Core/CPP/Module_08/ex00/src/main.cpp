#include "../inc/easyfind.hpp"

int main()
{
    std::vector<int> v;
    std::deque<int> d;
    std::list<int> l;
    std::vector<int> v2;

    for (int i = 1; i < 6; i++)
        v.push_back(i);
    for (int i = 7; i > 2; i--)
        d.push_back(i);
    for (int i = 5; i < 10; i++)
        l.push_back(i);
    for (int i = 6; i < 11; i++)
        v2.push_back(i);

    try {
        std::cout << "----- vector -----" << std::endl;
        std::cout << *::easyfind(v, 5) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Value not found" << std::endl;
    }
    try {
        std::cout << "----- deque -----" << std::endl;
        std::cout << *::easyfind(d, 5) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Value not found" << std::endl;
    }
    try {
        std::cout << "----- list -----" << std::endl;
        std::cout << *::easyfind(l, 5) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Value not found" << std::endl;
    }
    try {
        std::cout << "----- vector (not found) -----" << std::endl;
        std::cout << *::easyfind(v2, 5) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Value not found" << std::endl;
    }

    return (0);
}
