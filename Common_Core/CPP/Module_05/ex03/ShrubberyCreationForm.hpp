#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
    private:
        std::string _target;
        
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator = (const ShrubberyCreationForm &copy);
        ShrubberyCreationForm(std::string target);
        virtual ~ShrubberyCreationForm();

        void        beSigned(const Bureaucrat &b);
        void        action(void) const;

        std::string getTarget(void) const;
};

#endif
