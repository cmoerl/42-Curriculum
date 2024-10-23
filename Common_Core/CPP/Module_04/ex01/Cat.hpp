#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain   *_catBrain;

    public:
        Cat();
        Cat(const Cat &copy);
        Cat &operator = (const Cat &copy);
        virtual ~Cat();

        void    makeSound() const;
};

#endif
