#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
    std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), _target(other._target) {
    std::cout << "RobotomyRequestForm copy constructor" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
    std::cout << "RobotomyRequestForm assignation operator" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm for " << getTarget() << " has been created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm for " << getTarget() << " has been destroyed" << std::endl;
}

void RobotomyRequestForm::beSigned(Bureaucrat const &b) {
    AForm::beSigned(b);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > _reqEx)
        throw GradeTooLowException();
    else if (!_signed)
        throw FormNotSignedException();
    std::cout << "* Drilling noises *" << std::endl;
    srand(time(0));
    if (rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << getTarget() << " robotomization failed" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
    return (_target);
}
