#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Trash.hpp"

class   MateriaSource: public IMateriaSource
{
    private:
        AMateria        *_materias[4];
        static Trash    _trash;

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource &operator = (const MateriaSource &copy);
        virtual ~MateriaSource();

        void        learnMateria(AMateria*);
        AMateria    *createMateria(std::string const &type);
};

#endif
