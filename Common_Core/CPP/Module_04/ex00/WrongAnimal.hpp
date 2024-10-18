#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class   WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal &operator = (const WrongAnimal &copy);
        virtual ~WrongAnimal();

        void    makeSound() const;

        std::string getType() const;

};

#endif
