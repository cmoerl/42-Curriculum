#include "MutantStack.hpp"
#include <iostream>

int main()
{
    std::cout << "--- test from the subject ---" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "--- additional tests ---" << std::endl;

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
