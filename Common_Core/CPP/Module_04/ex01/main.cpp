#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal  *animals[10];

    for (int i = 0; i < 5; i++)
        animals[i] = new Dog;
    std::cout << std::endl;

    for (int i = 5; i < 10; i++)
        animals[i] = new Cat;
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }
    std::cout << std::endl;

    Dog *dogOG = dynamic_cast<Dog*>(animals[0]);
    Dog dogCopy(*dogOG);
    std::cout << std::endl;

    std::cout << dogCopy.getType() << std::endl;
    dogCopy.makeSound();
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
        delete animals[i];

    return (0);
}

/* 
    Deep Copy: 
        - Used when an object contains dynamically allocated memory.
        - Involves allocating new memory and copying the actual values 
            from the original object.
        - Requires explicitly defining the copy constructor and copy assignment 
            operator.
        - Ensures that the original and the copy are completely independent.
        - When implemented incorrectly, the copy may still point to the 
            original memory, leading to issues like double deletion.

    Shallow Copy: 
        - Used when an object does not contain dynamically allocated memory 
            or when a simple copy of the values is sufficient.
        - Involves copying the values of all member variables to the new object.
        - The default copy constructor and copy assignment operator provided 
            by the compiler perform a shallow copy.
        - The original and the copy share the same memory for dynamically 
            allocated members, leading to potential issues if one object modifies 
            the shared memory.
*/
