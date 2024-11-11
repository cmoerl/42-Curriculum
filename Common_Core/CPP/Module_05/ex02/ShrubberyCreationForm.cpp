#include "ShrubberyCreationForm.hpp"

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

void ShrubberyCreationForm::action(void) const {
    std::ofstream file((getTarget() + "_shrubbery").c_str());
    if (file.is_open()) {
        file << "      /\\      " << std::endl;
        file << "     /\\*\\     " << std::endl;
        file << "    /\\O\\*\\    " << std::endl;
        file << "   /*/\\/\\/\\   " << std::endl;
        file << "  /\\O\\/\\*\\/\\  " << std::endl;
        file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
        file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
        file << "      ||      " << std::endl;
        file << "      ||      " << std::endl;
        file << "      ||      " << std::endl;
        file << std::endl;
        file << "      ||      " << std::endl;
        file << "      ||      " << std::endl;
        file << "      ||      " << std::endl;
        file << std::endl;
        file << "      ||      " << std::endl;
        file << "      ||      " << std::endl;
        file << "      ||      " << std::endl;
        file << std::endl;
        file << "      ||      " << std::endl;
        file << "      ||      " << std::endl;
        file << "      ||      " << std::endl;
        file.close();
    }
}

std::string ShrubberyCreationForm::getTarget(void) const {
    return (_target);
}
