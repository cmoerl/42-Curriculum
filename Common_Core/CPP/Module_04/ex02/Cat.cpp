#include "Cat.hpp"

Cat::Cat(): Animal() {
    std::cout << "Cat default constructor" << std::endl;
    type = "Cat";
    _catBrain = new Brain();
}

Cat::Cat(const Cat &copy): Animal(copy), _catBrain(new Brain(*copy._catBrain)) {
    std::cout << "Cat copy constructor" << std::endl;
}

Cat &Cat::operator = (const Cat &copy) {
    std::cout << "Cat copy assignment operator" << std::endl;
    if (this != &copy) {
        Animal::operator = (copy);
        delete _catBrain;
        _catBrain = new Brain(*copy._catBrain);
    }
    return (*this);
}

Cat::~Cat() {
    std::cout << "Cat destructor" << std::endl;
    delete _catBrain;
}

void    Cat::makeSound() const {
    std::cout << "meow" << std::endl;
}
