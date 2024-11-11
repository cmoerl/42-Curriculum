#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern  someRandomIntern;
    AForm*   rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *rrf << std::endl;

    Bureaucrat  employee("employee", 70);
    std::cout << employee << std::endl;
    employee.signForm(*rrf);
    employee.executeForm(*rrf);

    Bureaucrat  boss("boss", 1);
    std::cout << boss << std::endl;
    boss.signForm(*rrf);
    boss.executeForm(*rrf);

    delete rrf;
}
