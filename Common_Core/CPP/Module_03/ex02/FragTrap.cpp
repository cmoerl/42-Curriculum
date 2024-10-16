#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
    this->_name = "";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap has been created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy) {
    if (this->getName().empty())
        std::cout << "Copy of FragTrap has been created" << std::endl;
    else
    {
        std::cout << "Copy of FragTrap named " << this->getName() 
        << " has been created" << std::endl;
    }
}

FragTrap &FragTrap::operator = (const FragTrap &copy) {
    if (this != &copy)
        ClapTrap::operator = (copy);
    if (this->getName().empty())
        std::cout << "Copy of FragTrap has been assigned" << std::endl;
    else
    {
        std::cout << "Copy of FragTrap named " << this->getName() 
        << " has been assigned" << std::endl;
    }
    return (*this);
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap named " << name << " has been created" << std::endl;
}

FragTrap::~FragTrap() {
    if (this->getName().empty())
        std::cout << "FragTrap has been destroyed" << std::endl;
    else
        std::cout << "FragTrap named " << this->getName() << " has been destroyed" << std::endl;
}

void    FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << this->getName() 
    << " holds up its hand for a high five!" << std::endl;
}
