#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("default", 25, 5), _target("default") {
    std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy) {
    std::cout << "PresidentialPardonForm copy constructor" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &copy) {
    std::cout << "PresidentialPardonForm copy assignment operator" << std::endl;
    if (this != &copy)
        AForm::operator=(copy);
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm for " << getTarget() << " has been created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm for " << getTarget() << " has been destroyed" << std::endl;
}

void PresidentialPardonForm::beSigned(const Bureaucrat &b) {
    AForm::beSigned(b);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > _reqEx)
        throw GradeTooLowException();
    else if (!_signed)
        throw FormNotSignedException();
    std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const {
    return (_target);
}
