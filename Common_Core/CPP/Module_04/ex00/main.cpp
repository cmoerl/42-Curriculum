#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;
    const WrongAnimal*  wrongmeta = new WrongAnimal();
    const WrongAnimal*  k = new WrongCat();
    const WrongCat*     l = new WrongCat();
    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl;
    std::cout << k->getType() << " " << std::endl;
    std::cout << l->getType() << " " << std::endl;
    k->makeSound();
    l->makeSound();
    wrongmeta->makeSound();
    std::cout << std::endl;

    delete meta;
    delete i;
    delete j;
    delete wrongmeta;
    delete k;

    return (0);
}
