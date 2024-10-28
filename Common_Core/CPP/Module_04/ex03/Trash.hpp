#ifndef TRASH_HPP
#define TRASH_HPP

#include "AMateria.hpp"


class Trash {
    private:
        struct s_trash{
            AMateria    *materia;
            s_trash     *next;
        };
        s_trash *trash;

    public:
        Trash();
        Trash(const Trash& other);
        Trash& operator=(const Trash& other);
        ~Trash();

        void    addToTrash(AMateria *materia);
        void    cleanTrash();
};

#endif
