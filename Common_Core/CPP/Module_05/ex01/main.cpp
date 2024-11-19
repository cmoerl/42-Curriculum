#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try 
    {
        Form    form1("Form 1", 151, 100);
    }
    catch(std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Form    form2("Form 2", 150, 0);
    }
    catch(std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat  employee("Hans", 150);
        Form        registration("Registration Form", 100, 100);

        std::cout << registration << std::endl;

        employee.signForm(registration);
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat  employee("Franz", 50);
        Form        registration("Registration Form", 100, 100);

        employee.signForm(registration);

        std::cout << registration << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return (0);
}
