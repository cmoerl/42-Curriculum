#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class   Animal
{
    protected:
        std::string type;

    public:
        Animal();
        Animal(const Animal &copy);
        Animal &operator = (const Animal &copy);
        virtual ~Animal();

        std::string getType() const;

        virtual void    makeSound() const = 0;
};

#endif

/* 
    abstract classes:
        - can only be used as base class (not instantiable)
        - defined by having at least one pure virtual function
        --> virtual function with a pure specifier (= 0)
        - cannot be used as a parameter type, function return 
            type or type of an explicit conversion
        - a class derived from an abstract class will also be 
            abstract unless the pure virtual functions are overridden

*/
