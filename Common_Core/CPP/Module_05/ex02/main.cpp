#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat b1("Bureaucrat 1", 1);
    Bureaucrat b2("Bureaucrat 2", 150);

    PresidentialPardonForm ppf("Hans");
    RobotomyRequestForm rrf("42");
    ShrubberyCreationForm scf("Vienna");

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    std::cout << ppf << std::endl;
    std::cout << rrf << std::endl;
    std::cout << scf << std::endl;

    b1.signForm(ppf);
    b1.signForm(rrf);
    b1.signForm(scf);

    b1.executeForm(ppf);
    b1.executeForm(rrf);
    b1.executeForm(scf);

    b2.signForm(ppf);
    b2.signForm(rrf);
    b2.signForm(scf);

    b2.executeForm(ppf);
    b2.executeForm(rrf);
    b2.executeForm(scf);

    return 0;
}
