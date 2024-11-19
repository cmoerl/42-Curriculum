#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("b1", 77);
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat employee("Hans", 150);

        employee.incrementGrade();
        std::cout << employee << std::endl;
        employee.decrementGrade();
        std::cout << employee << std::endl;
        employee.decrementGrade();
        std::cout << employee << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat boss("Franz", 1);

        boss.decrementGrade();
        std::cout << boss << std::endl;
        boss.incrementGrade();
        std::cout << boss << std::endl;
        boss.incrementGrade();
        std::cout << boss << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat ceo("Gans", 0);
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat intern("Grant", 151);
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return (0);
}
