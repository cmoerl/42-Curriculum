#include "Animal.hpp"

Animal::Animal(): type("Animal") {
    std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal &copy): type(copy.type) {
    std::cout << "Animal copy constructor" << std::endl;
}

Animal &Animal::operator = (const Animal &copy) {
    std::cout << "Animal copy assignment operator" << std::endl;
    if (this != &copy)
        type = copy.type;
    return (*this);
}

Animal::~Animal() {
    std::cout << "Animal destructor" << std::endl;
}

void    Animal::makeSound() const {
    std::cout << "* chorus of animal sounds *" << std::endl;
}

std::string Animal::getType() const {
    return (type);
}
