#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &) {
    std::cout << "ScalarConverter copy constructor" << std::endl;
}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &copy) {
    if (this != &copy) {
        // do nothing
    }
    std::cout << "ScalarConverter copy assignment operator" << std::endl;
    return (*this);
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter destructor" << std::endl;
}

void    ScalarConverter::convert(const std::string &literal) {
    char    charLiteral;
    int     intLiteral;
    float   floatLiteral;
    double  doubleLiteral;

    try {
        charLiteral = static_cast<char>(std::stoi(literal));
        std::cout << "char: " << charLiteral << std::endl;
    } catch (std::exception &e) {
        if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff" || literal == "inf" || literal == "inff")
            std::cout << "char: impossible" << std::endl;
        else
            std::cout << "char: non displayable" << std::endl;
    }

    try {
        intLiteral = std::stoi(literal);
        std::cout << "int: " << intLiteral << std::endl;
    } catch (std::out_of_range &e) {
        std::cout << "int: impossible" << std::endl;
    } catch (std::exception &e) {
        std::cout << "int: impossible" << std::endl;
    }

    try {
        floatLiteral = std::stof(literal);
        std::cout << "float: " << floatLiteral << std::endl;
    } catch (std::out_of_range &e) {
        std::cout << "float: impossible" << std::endl;
    } catch (std::exception &e) {
        if (literal == "-inff" || literal == "-inf")
            std::cout << "float: -inff" << std::endl;
        else if (literal == "+inff" || literal == "+inf")
            std::cout << "float: +inff" << std::endl;
        else if (literal == "inff" || literal == "inf")
            std::cout << "float: inff" << std::endl;
        else if (literal == "nanf" || literal == "nan")
            std::cout << "float: nanf" << std::endl;
        else
            std::cout << "float: impossible" << std::endl;
    }

    try {
        doubleLiteral = std::stod(literal);
        std::cout << "double: " << doubleLiteral << std::endl;
    } catch (std::out_of_range &e) {
        std::cout << "double: impossible" << std::endl;
    } catch (std::exception &e) {
        if (literal == "-inf")
            std::cout << "double: -inf" << std::endl;
        else if (literal == "+inf")
            std::cout << "double: +inf" << std::endl;
        else if (literal == "inf")
            std::cout << "double: inf" << std::endl;
        else if (literal == "nan")
            std::cout << "double: nan" << std::endl;
        else
            std::cout << "double: impossible" << std::endl;
    }
}
