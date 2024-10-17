#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class   DiamondTrap: public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap &copy);
        DiamondTrap &operator = (const DiamondTrap &copy);
        DiamondTrap(std::string name);
        ~DiamondTrap();

        void    whoAmI();
        std::string getName() const;

    private:
        std::string _name;
};

#endif
