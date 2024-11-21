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

    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        charLiteral = literal[0];
        if (charLiteral >= 32 && charLiteral <= 126)
            std::cout << "char: '" << charLiteral << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        intLiteral = static_cast<int>(charLiteral);
        std::cout << "int: " << intLiteral << std::endl;
        floatLiteral = static_cast<float>(charLiteral);
        std::cout << "float: " << std::fixed << std::setprecision(1) << floatLiteral << "f" << std::endl;
        doubleLiteral = static_cast<double>(charLiteral);
        std::cout << "double: " << doubleLiteral << std::endl;
        return;
    }

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
        if (value > std::numeric_limits<int>::max() || value < -std::numeric_limits<int>::max()) {
            throw std::out_of_range("Int overflow");
        }
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
        if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()) {
            throw std::out_of_range("Float overflow");
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
        if (doubleLiteral > std::numeric_limits<double>::max() || doubleLiteral < -std::numeric_limits<double>::max()) {
            throw std::out_of_range("Double overflow");
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
