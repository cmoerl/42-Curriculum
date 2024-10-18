#include "Cat.hpp"

Cat::Cat(): Animal() {
    type = "cat";
    std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy) {
    std::cout << "Cat copy constructor" << std::endl;
}

Cat &Cat::operator = (const Cat &copy) {
    if (this != &copy)
        Animal::operator = (copy);
    std::cout << "Cat copy assignment operator" << std::endl;
    return (*this);
}

Cat::~Cat() {
    std::cout << "Cat destructor" << std::endl;
}

void    Cat::makeSound() const {
    std::cout << "meow" << std::endl;
}
