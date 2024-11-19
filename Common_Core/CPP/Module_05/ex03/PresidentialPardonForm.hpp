#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class   PresidentialPardonForm: public AForm
{
    private:
        std::string _target;
        
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator = (const PresidentialPardonForm &copy);
        PresidentialPardonForm(std::string target);
        virtual ~PresidentialPardonForm();

        void    beSigned(const Bureaucrat &b);
        void    execute(Bureaucrat const & executor) const;

        std::string getTarget(void) const;

};

#endif
