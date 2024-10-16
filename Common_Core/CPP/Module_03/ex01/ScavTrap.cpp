#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
    this->_name = "";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap has been created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy) {
    if (this->getName().empty())
        std::cout << "Copy of ScavTrap has been created" << std::endl;
    else
    {
        std::cout << "Copy of ScavTrap named " << this->getName() 
        << " has been created" << std::endl;
    }
}

ScavTrap &ScavTrap::operator = (const ScavTrap &copy) {
    if (this != &copy)
        ClapTrap::operator = (copy);
    if (this->getName().empty())
        std::cout << "Copy of ScavTrap has been assigned" << std::endl;
    else
    {
        std::cout << "Copy of ScavTrap named " << this->getName() 
        << " has been assigned" << std::endl;
    }
    return (*this);
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap named " << name << " has been created" << std::endl;
}

ScavTrap::~ScavTrap() {
    if (this->getName().empty())
        std::cout << "ScavTrap has been destroyed" << std::endl;
    else
        std::cout << "ScavTrap named " << this->getName() << " has been destroyed" << std::endl;
}

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->getName() 
    << " is now in Gate keeper mode!" << std::endl;
}

void    ScavTrap::attack(const std::string &target) {
    if (!ScavTrap::checkAbility())
        return ;
    std::cout << "ScavTrap " << this->getName() << " attacks " 
    << target << ", causing " << this->getAttackDamage() 
    << " points of damage!" << std::endl;
    this->setEnergyPoints(this->getEnergyPoints() - 1);
}
