#include "../inc/easyfind.hpp"

template <typename T>
void printContainer(const T& container) {
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v;
    std::deque<int> d;
    std::list<int> l;
    std::vector<int> v2;
    std::vector<int> empty;

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
        printContainer(v);
        std::vector<int>::iterator it = ::easyfind(v, 5);
        std::cout << "Found " << *it << " at position " 
                  << std::distance(v.begin(), it) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Value not found" << std::endl;
    }

    try {
        std::cout << "----- deque -----" << std::endl;
        printContainer(d);
        std::deque<int>::iterator it = ::easyfind(d, 5);
        std::cout << "Found " << *it << " at position " 
                  << std::distance(d.begin(), it) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Value not found" << std::endl;
    }

    try {
        std::cout << "----- list -----" << std::endl;
        printContainer(l);
        std::list<int>::iterator it = ::easyfind(l, 5);
        std::cout << "Found " << *it << " at position " 
                  << std::distance(l.begin(), it) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Value not found" << std::endl;
    }

    try {
        std::cout << "----- number not found -----" << std::endl;
        printContainer(v2);
        std::vector<int>::iterator it = ::easyfind(v2, 5);
        std::cout << "Found " << *it << " at position " 
                  << std::distance(v2.begin(), it) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Value not found" << std::endl;
    }

    try {
        std::cout << "----- empty vector -----" << std::endl;
        printContainer(empty);
        std::vector<int>::iterator it = ::easyfind(empty, 1);
        std::cout << "Found " << *it << " at position " 
                  << std::distance(empty.begin(), it) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Value not found" << std::endl;
    }

    v.push_back(5);
    try {
        std::cout << "----- vector with duplicates -----" << std::endl;
        printContainer(v);
        std::vector<int>::iterator it = ::easyfind(v, 5);
        std::cout << "Found " << *it << " at position " 
                  << std::distance(v.begin(), it) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Value not found" << std::endl;
    }

    return (0);
}
