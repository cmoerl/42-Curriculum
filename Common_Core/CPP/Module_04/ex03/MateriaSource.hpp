#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class   MateriaSource: public IMateriaSource
{
    private:
        AMateria    *_materias[4];
        AMateria    *_trash[100];
        int         _trashCount;


    public:
        MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource &operator = (const MateriaSource &copy);
        virtual ~MateriaSource();

        void        learnMateria(AMateria*);
        AMateria    *createMateria(std::string const &type);
};

#endif
