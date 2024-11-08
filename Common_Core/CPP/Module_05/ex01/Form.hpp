#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form 
{
    private:
        std::string const   _name;
        bool                _signed;
        int const           _reqSign;
        int const           _reqEx;

    public:
        Form();
        Form(const Form &copy);
        Form &operator = (const Form &copy);
        Form(std::string name, int reqSign, int reqEx);
        ~Form();

        std::string getName(void) const;
        bool        getSigned(void) const;
        int         getReqSign(void) const;
        int         getReqEx(void) const;

        void        beSigned(const Bureaucrat &b);

        class   GradeTooHighException: public std::exception {
            public:
                const char* what() const throw();

        };
        class   GradeTooLowException: public std::exception {
            public:
                const char* what() const throw();

        };

};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif
