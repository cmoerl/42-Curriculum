#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
    public:

        ClapTrap();
        ClapTrap(const ClapTrap &copy);
        ClapTrap &operator = (const ClapTrap &copy);
        ClapTrap(std::string name);
        ~ClapTrap();

        std::string     getName(void) const;
        unsigned int    getHitPoints(void) const;
        unsigned int    getEnergyPoints(void) const;
        unsigned int    getAttackDamage(void) const;
        void            setHitPoints(const unsigned int hitPoints);
        void            setEnergyPoints(const unsigned int energyPoints);

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        bool    checkAbility() const;

    protected:
        std::string          _name;
        unsigned int         _hitPoints;
        unsigned int         _energyPoints;
        const unsigned int   _attackDamage;
};

#endif
