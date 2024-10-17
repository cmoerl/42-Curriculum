#include "DiamondTrap.hpp"
#include <string>

DiamondTrap::DiamondTrap(): ClapTrap("_clap_name"), ScavTrap(), FragTrap() {
    this->_name = "";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap has been created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy), _name(copy._name) {
    if (DiamondTrap::_name.empty())
        std::cout << "Copy of DiamondTrap has been created" << std::endl;
    else
    {
        std::cout << "Copy of DiamondTrap named " << DiamondTrap::_name 
        << " has been created" << std::endl;
    }
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &copy) {
    if (this != &copy)
    {
        ClapTrap::operator = (copy);
        ScavTrap::operator = (copy);
        FragTrap::operator = (copy);
    }
    if (DiamondTrap::_name.empty())
        std::cout << "Copy of DiamondTrap has been assigned" << std::endl;
    else
    {
        std::cout << "Copy of DiamondTrap named " << DiamondTrap::_name 
        << " has been assigned" << std::endl;
    }
    return (*this);
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
    this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap named " << DiamondTrap::_name << " has been created" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    if (DiamondTrap::_name.empty())
        std::cout << "DiamondTrap has been destroyed" << std::endl;
    else
        std::cout << "DiamondTrap named " << DiamondTrap::_name << " has been destroyed" << std::endl;
}

// std::string DiamondTrap::getName() const {
//     return this->_name;
// }

void    DiamondTrap::whoAmI() {
    if (!this->checkAbility())
        return ;
    std::cout << "DiamondTrap " << DiamondTrap::_name << "'s ClapTrap name is " 
    << ClapTrap::_name << "!" << std::endl;
}
