#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <ios>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("default", 145, 137), _target("default") {
    std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(copy) {
    std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &copy) {
    std::cout << "ShrubberyCreationForm copy assignment operator" << std::endl;
    if (this != &copy)
        AForm::operator=(copy);
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm for " << getTarget() << " has been created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm for " << getTarget() << " has been destroyed" << std::endl;
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &b) {
    AForm::beSigned(b);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > _reqEx)
        throw GradeTooLowException();
    else if (!_signed)
        throw FormNotSignedException();
    std::ofstream file((getTarget() + "_shrubbery").c_str());
    if (!file.is_open()) {
        throw std::ios_base::failure("Failed to open file");
    }
    try {
        file << "      /\\      \n"
            << "     /\\*\\     \n"
            << "    /\\O\\*\\    \n"
            << "   /*/\\/\\/\\   \n"
            << "  /\\O\\/\\*\\/\\  \n"
            << " /\\*\\/\\*\\/\\/\\ \n"
            << "/\\O\\/\\/*/\\/O/\\\n"
            << "      ||      \n"
            << "      ||      \n"
            << "      ||      \n\n"
            << "      ||      \n"
            << "      ||      \n"
            << "      ||      \n\n"
            << "      ||      \n"
            << "      ||      \n"
            << "      ||      \n\n"
            << "      ||      \n"
            << "      ||      \n"
            << "      ||      \n";
    }
    catch (const std::ios_base::failure &e) {
        file.close();
        throw e;
    }
    file.close();
}

std::string ShrubberyCreationForm::getTarget(void) const {
    return (_target);
}
