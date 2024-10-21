#include "Dog.hpp"

Dog::Dog(): Animal() {
    std::cout << "Dog default constructor" << std::endl;
    type = "Dog";
    _dogBrain = new Brain();
}

Dog::Dog(const Dog &copy): Animal(copy), _dogBrain(new Brain(*copy._dogBrain)) {
    std::cout << "Dog copy constructor" << std::endl;
}

Dog &Dog::operator = (const Dog &copy) {
    std::cout << "Dog copy assignment operator" << std::endl;
    if (this != &copy) {
        Animal::operator = (copy);
        *_dogBrain = *copy._dogBrain;
    }
    return (*this);
}

Dog::~Dog() {
    std::cout << "Dog destructor" << std::endl;
    delete _dogBrain;
}

void    Dog::makeSound() const {
    std::cout << "woof" << std::endl;
}
