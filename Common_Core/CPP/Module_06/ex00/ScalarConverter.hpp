#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

class   ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator = (const ScalarConverter &copy);
        ~ScalarConverter();

    public:
        static void    convert(const std::string &literal);
};

#endif
