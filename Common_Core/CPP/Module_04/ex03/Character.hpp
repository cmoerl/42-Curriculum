#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class   Character: public ICharacter
{
    private:
        AMateria    *_slots[4];
        std::string _name;
        AMateria    *_unequipped[10];
        int         _unequippedCount;

    protected:

    public:
        Character();
        Character(std::string name);
        Character(const Character &copy);
        Character &operator = (const Character &copy);
        ~Character();

        std::string const &getName() const;
        void        equip(AMateria *m);
        void        unequip(int idx);
        void        use(int idx, ICharacter &target);

};

#endif
