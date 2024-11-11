#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm: public AForm
{
    private:
        std::string _target;
        
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator = (const RobotomyRequestForm &copy);
        RobotomyRequestForm(std::string target);
        virtual ~RobotomyRequestForm();

        void        beSigned(const Bureaucrat &b);
        void        action(void) const;

        std::string getTarget(void) const;

};

#endif
