#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("default"), _signed(false), _reqSign(150), _reqEx(150) {
    std::cout << "AForm default constructor" << std::endl;
}

AForm::AForm(const AForm &copy): _name(copy._name), _signed(false), _reqSign(copy._reqSign), _reqEx(copy._reqEx) {
    std::cout << "AForm copy constructor" << std::endl;
}

AForm &AForm::operator = (const AForm &copy) {
    std::cout << "AForm copy assigment operator" << std::endl;
    if (this != &copy)
        _signed = copy._signed;
    return (*this);
}

AForm::AForm(std::string name, int reqSign, int reqEx): _name(name), _signed(false), _reqSign(reqSign), _reqEx(reqEx) {
    if (_reqSign > 150 || _reqEx > 150)
        throw GradeTooLowException();
    else if (_reqSign < 1 || _reqEx < 1)
        throw GradeTooHighException();
    std::cout << "AForm " << getName() << " has been created" << std::endl;
}

AForm::~AForm() {
    std::cout << "AForm destructor" << std::endl;
}

std::string AForm::getName(void) const {
    return (_name);
}

bool        AForm::getSigned(void) const {
    return (_signed);
}

int         AForm::getReqSign(void) const {
    return (_reqSign);
}

int         AForm::getReqEx(void) const {
    return (_reqEx);
}

void        AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() <= _reqSign && _signed == false)
        _signed = true;
    else if (_signed == true)
        throw FormAlreadySignedException();
    else
        throw GradeTooLowException();
}

void    AForm::execute(const Bureaucrat &executor) const {
    if (executor.getGrade() > _reqEx)
        throw GradeTooLowException();
    else if (!_signed)
        throw FormNotSignedException();
    std::cout << "AForm action" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return ("grade too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("grade too low");
}

const char* AForm::FormNotSignedException::what() const throw() {
    return ("form not signed");
}

const char* AForm::FormAlreadySignedException::what() const throw() {
    return ("form already signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
    out << f.getName() << "\nrequired grade to sign: " << 
    f.getReqSign() << "\nrequired grade to execute: " << 
    f.getReqEx() << "\nstatus: " << (f.getSigned() ? "signed" : "not signed");
    return (out);
}
