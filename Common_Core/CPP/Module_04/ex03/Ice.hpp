#pragma once

#include "AMateria.hpp"

class   Ice: public AMateria
{
    private:

    protected:

    public:
        Ice();
        Ice(const Ice &copy);
        Ice &operator = (const Ice &copy);
        ~Ice();

        AMateria    *clone() const;
        void        use(ICharacter& target);
};
