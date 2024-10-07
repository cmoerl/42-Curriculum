#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB();
        std::string getName() const;
        void        setName(std::string name);
        std::string getWeaponType() const;
        void        setWeapon(Weapon &weapon);
        void        attack() const;

    private:
        std::string _name;
        Weapon      *_weapon;
};

#endif
