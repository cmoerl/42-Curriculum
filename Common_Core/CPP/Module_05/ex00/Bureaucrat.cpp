#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {
    std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade) {
    std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &copy) {
    std::cout << "Bureaucrat copy assignment operator" << std::endl;
    if (this != &copy) {
        _grade = copy._grade;
    }
    return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
    std::cout << "Bureaucrat " << _name << " has been created with grade " << _grade << std::endl;
    if (_grade > 150)
        throw GradeTooLowException();
    else if (_grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << _name << " has been destroyed" << std::endl;
}

std::string Bureaucrat::getName(void) const {
    return (_name);
}

int         Bureaucrat::getGrade(void) const {
    return (_grade);
}

void        Bureaucrat::incrementGrade(void) {
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void        Bureaucrat::decrementGrade(void) {
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Bureaucrat's grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Bureaucrat's grade too low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (out);
}
