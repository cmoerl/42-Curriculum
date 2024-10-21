#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Wrong Animal") {
    std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy): type(copy.type) {
    std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &copy) {
    if (this != &copy)
        type = copy.type;
    std::cout << "WrongAnimal copy assignment operator" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor" << std::endl;
}

void    WrongAnimal::makeSound() const {
    std::cout << "* chorus of animal sounds *" << std::endl;
}

std::string WrongAnimal::getType() const {
    return (type);
}
