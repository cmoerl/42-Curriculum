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
    // Handle special float cases first
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (literal == "nanf" ? "nanf" : literal) << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        return;
    }

    // Handle special double cases
    if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }

    // Handle character literals
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        char charLiteral = literal[0];
        if (isprint(charLiteral))
            std::cout << "char: '" << charLiteral << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(charLiteral) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) 
                  << static_cast<float>(charLiteral) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) 
                  << static_cast<double>(charLiteral) << std::endl;
        return;
    }

    // Handle numeric literals
    std::string numStr = literal;
    bool isFloat = (literal.find('f') != std::string::npos);
    
    // Validate input format
    if (isFloat) {
        // Check if 'f' is the last character and the rest is a valid number
        if (literal[literal.length() - 1] != 'f' || literal.find('f') != literal.length() - 1) {
            throw std::invalid_argument("Invalid float format");
        }
        numStr = literal.substr(0, literal.length() - 1);
    }

    // Check for invalid characters
    // size_t pos;
    try {
        char *end;
        double value = strtod(numStr.c_str(), &end);
        // Check if there are any remaining characters after the number
        if (*end != '\0') {
            throw std::invalid_argument("Invalid input format");
        }
        
        // Set precision based on input
        size_t decimalPos = numStr.find('.');
        int precision = 1;  // Default precision
        if (decimalPos != std::string::npos) {
            // Count actual decimal places in the input
            std::string decimals = numStr.substr(decimalPos + 1);
            if (isFloat) {
                decimals = decimals.substr(0, decimals.length()); // Keep all decimal places for float
            }
            precision = decimals.empty() ? 1 : decimals.length();
        }
        
        // Character conversion
        if (value >= -128 && value <= 127) {
            if (value >= 32 && value <= 126)
                std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: impossible" << std::endl;
        }

        // Integer conversion
        if (value <= INT_MAX && value >= INT_MIN && value == std::floor(value))
            std::cout << "int: " << static_cast<int>(value) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;

        // Float conversion
        if (std::abs(value) <= std::numeric_limits<float>::max()) {
            float floatValue = static_cast<float>(value);
            std::cout << "float: " << std::fixed << std::setprecision(precision) 
                      << floatValue << "f" << std::endl;
        } else {
            std::cout << "float: impossible" << std::endl;
        }

        // Double conversion
        std::cout << "double: " << std::fixed << std::setprecision(precision) 
                  << value << std::endl;

    } catch (std::exception &e) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
}
