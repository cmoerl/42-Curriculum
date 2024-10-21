#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class   AMateria
{
    protected:

    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria &copy);
        AMateria &operator = (const AMateria &copy);
        ~AMateria();

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif
