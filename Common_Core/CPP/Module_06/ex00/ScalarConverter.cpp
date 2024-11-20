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
    char                charLiteral;
    int                 intLiteral;
    float               floatLiteral;
    double              doubleLiteral;
    std::istringstream  iss(literal);

    try {
        double  value;
        if (iss >> value) {
            charLiteral = static_cast<char>(value);
            if (value >= 32 && value <= 126)
                std::cout << "char: '" << charLiteral << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        } else {
            throw std::invalid_argument("Invalid input");
        }
    } catch (std::exception &e) {
        std::cout << "char: impossible" << std::endl;
    }

    try {
        double  value;
        iss.clear();
        iss.seekg(0);
        if (!(iss >> value)) 
            throw std::invalid_argument("Invalid input");
        if (value > INT_MAX || value < INT_MIN)
            throw std::out_of_range("Int overflow");
        intLiteral = static_cast<int>(value);
        std::cout << "int: " << intLiteral << std::endl;
    } catch (std::exception &e) {
        std::cout << "int: impossible" << std::endl;
    }

    try {
        double  value;
        iss.clear();
        iss.seekg(0);
        if (!(iss >> value)) {
            throw std::invalid_argument("Invalid input");
        }
        floatLiteral = static_cast<float>(value);
        std::cout << "float: " << std::fixed << std::setprecision(1) << floatLiteral << "f" << std::endl;
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
        iss.clear();
        iss.seekg(0);
        if (!(iss >> doubleLiteral)) {
            throw std::invalid_argument("Invalid input");
        }
        std::cout << std::fixed << std::setprecision(1) << "double: " << doubleLiteral << std::endl;
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
