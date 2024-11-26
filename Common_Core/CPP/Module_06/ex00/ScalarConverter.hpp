#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <climits>
#include <limits>
#include <cmath>


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
