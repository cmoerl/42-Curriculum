#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        std::string getName() const;
        void        setName(std::string name);
        std::string getWeaponType() const;
        void        attack() const;

    private:
        std::string _name;
        Weapon      &_weapon;
};

#endif
