#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
    this->_name = "";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}


ScavTrap(const ScavTrap &copy);
ScavTrap &operator = (const ScavTrap &copy);
ScavTrap(std::string name);
~ScavTrap();

void    guardGate();