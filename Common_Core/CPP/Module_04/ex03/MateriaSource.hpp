#pragma once

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class   MateriaSource: public IMateriaSource
{
    private:
        AMateria    *_materias[4];

    protected:

    public:
        AMateria    *leftover[100];

        MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource &operator = (const MateriaSource &copy);
        ~MateriaSource();

        void        learnMateria(AMateria*);
        AMateria    *createMateria(std::string const &type);
};
