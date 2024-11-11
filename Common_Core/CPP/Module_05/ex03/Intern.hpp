#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &copy);
    AForm *makeForm(std::string name, std::string target);
    ~Intern();

};

#endif
