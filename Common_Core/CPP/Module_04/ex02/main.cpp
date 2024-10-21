#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal  *animals[10];

    // Animal  animal;

    // std::cout << animal->getType() << std::endl;
    // animal->makeSound();

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

    for (int i = 0; i < 10; i++)
        delete animals[i];

    return (0);
}
