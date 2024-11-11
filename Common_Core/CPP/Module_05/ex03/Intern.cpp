#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern &copy) {
    std::cout << "Intern copy constructor" << std::endl;
    *this = copy;
}

Intern &Intern::operator=(const Intern &copy) {
    std::cout << "Intern assignation operator" << std::endl;
    (void)copy;
    return *this;
}

AForm *createRobotomyRequestForm(std::string target) {
    return (new RobotomyRequestForm(target));
}

AForm *createPresidentialPardonForm(std::string target) {
    return (new PresidentialPardonForm (target));
}

AForm *createShrubberyCreationForm(std::string target) {
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target) {
    const std::string names[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm *(*formCreators[])(std::string) = {createRobotomyRequestForm, createPresidentialPardonForm, createShrubberyCreationForm};

    for (int i = 0; i < 3; i++) {
        if (name == names[i]) {
            std::cout << "Intern creates " << name << " form for " << target << std::endl;
            return formCreators[i](target);
        }
    }
    std::cout << "Intern cannot create " << name << std::endl;
    return (NULL);
}

Intern::~Intern() {
    std::cout << "Intern destructor" << std::endl;
}
