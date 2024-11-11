#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("default"), _signed(false), _reqSign(150), _reqEx(150) {
    std::cout << "Form default constructor" << std::endl;
}

Form::Form(const Form &copy): _name(copy._name), _signed(false), _reqSign(copy._reqSign), _reqEx(copy._reqEx) {
    std::cout << "Form copy constructor" << std::endl;
}

Form &Form::operator = (const Form &copy) {
    std::cout << "Form copy assigment operator" << std::endl;
    if (this != &copy)
        _signed = copy._signed;
    return (*this);
}

Form::Form(std::string name, int reqSign, int reqEx): _name(name), _signed(false), _reqSign(reqSign), _reqEx(reqEx) {
    if (_reqSign > 150 || _reqEx > 150)
        throw GradeTooLowException();
    else if (_reqSign < 1 || _reqEx < 1)
        throw GradeTooHighException();
    std::cout << "Form " << getName() << " has been created" << std::endl;
}

Form::~Form() {
    std::cout << "Form destructor" << std::endl;
}

std::string Form::getName(void) const {
    return (_name);
}

bool        Form::getSigned(void) const {
    return (_signed);
}

int         Form::getReqSign(void) const {
    return (_reqSign);
}

int         Form::getReqEx(void) const {
    return (_reqEx);
}

void        Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() <= _reqSign && _signed == false)
        _signed = true;
    else if (_signed == true)
        std::cerr << "Form cannot be signed multiple times" << std::endl;
    else
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
    return ("grade too high");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("grade too low");
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
    out << f.getName() << "\nrequired grade to sign: " << 
    f.getReqSign() << "\nrequired grade to execute: " << 
    f.getReqEx() << "\nstatus: " << (f.getSigned() ? "signed" : "not signed");
    return (out);
}
