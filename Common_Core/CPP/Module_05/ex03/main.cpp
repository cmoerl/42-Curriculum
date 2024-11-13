#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
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
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Intern  someRandomIntern;
        AForm*   form1;

        form1 = someRandomIntern.makeForm("form1", "Bender");
        std::cout << *form1 << std::endl;

        Bureaucrat  employee("employee", 70);
        std::cout << employee << std::endl;
        employee.signForm(*form1);
        employee.executeForm(*form1);

        Bureaucrat  boss("boss", 1);
        std::cout << boss << std::endl;
        boss.signForm(*form1);
        boss.executeForm(*form1);

        delete form1;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return (0);
}
