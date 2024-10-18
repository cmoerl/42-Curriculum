#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
    type = "wrongcat";
    std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy) {
    std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat &WrongCat::operator = (const WrongCat &copy) {
    if (this != &copy)
        WrongAnimal::operator = (copy);
    std::cout << "WrongCat copy assignment operator" << std::endl;
    return (*this);
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor" << std::endl;
}

void    WrongCat::makeSound() const {
    std::cout << "meow" << std::endl;
}
