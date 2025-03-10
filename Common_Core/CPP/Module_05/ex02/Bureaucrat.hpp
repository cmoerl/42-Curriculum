#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class AForm;

class Bureaucrat
{
    private:
        std::string const   _name;
        int                 _grade;

    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator = (const Bureaucrat &copy);
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();

        std::string getName(void) const;
        int         getGrade(void) const;
        void        incrementGrade(void);
        void        decrementGrade(void);

        void        executeForm(AForm const & form);

        class   GradeTooHighException: public std::exception {
            public:
                const char* what() const throw();

        };
        class   GradeTooLowException: public std::exception {
            public:
                const char* what() const throw();

        };

        void    signForm(AForm &f);

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
