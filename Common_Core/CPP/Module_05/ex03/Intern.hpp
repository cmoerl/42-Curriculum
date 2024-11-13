#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &copy);
    ~Intern();

    AForm *makeForm(std::string name, std::string target);

    class FormNotFoundException : public std::exception
    {
        public:
            virtual const char *what() const throw();

    };
    
};

#endif
