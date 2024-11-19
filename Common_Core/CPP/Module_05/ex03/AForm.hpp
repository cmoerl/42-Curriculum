#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm 
{
    protected:
        std::string const   _name;
        bool                _signed;
        int const           _reqSign;
        int const           _reqEx;

    public:
        AForm();
        AForm(const AForm &copy);
        AForm &operator = (const AForm &copy);
        AForm(std::string name, int reqSign, int reqEx);
        virtual ~AForm();

        std::string getName(void) const;
        bool        getSigned(void) const;
        int         getReqSign(void) const;
        int         getReqEx(void) const;

        
        virtual void    execute(Bureaucrat const & executor) const = 0;
        virtual void    beSigned(const Bureaucrat &b) = 0;

        class   GradeTooHighException: public std::exception {
            public:
                const char* what() const throw();

        };
        class   GradeTooLowException: public std::exception {
            public:
                const char* what() const throw();

        };
        class   FormNotSignedException: public std::exception {
            public:
                const char* what() const throw();

        };
        class   FormAlreadySignedException: public std::exception {
            public:
                const char* what() const throw();

        };

};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif
