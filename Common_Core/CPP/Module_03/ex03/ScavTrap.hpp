#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const ScavTrap &copy);
        ScavTrap &operator = (const ScavTrap &copy);
        ScavTrap(std::string name);
        ~ScavTrap();

        void    guardGate();
        void    attack(const std::string &target);

    private:

};

#endif
