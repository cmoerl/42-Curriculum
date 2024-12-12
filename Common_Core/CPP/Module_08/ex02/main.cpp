#include "MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> m;

    for (int i = 0; i < 5; i++)
        m.push(i);

    std::cout << "Stack elements: ";
    for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Stack elements in reverse: ";
    for (MutantStack<int>::iterator it = --m.end(); it != m.begin(); --it)
        std::cout << *it << " ";
    std::cout << *m.begin() << std::endl;

    std::cout << "Top element: " << m.top() << std::endl;

    m.pop();
    std::cout << "Top element after pop: " << m.top() << std::endl;

    std::cout << "Stack size: " << m.size() << std::endl;

    return (0);
}
