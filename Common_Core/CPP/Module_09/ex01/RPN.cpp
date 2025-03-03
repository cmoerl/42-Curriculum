#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator = (const RPN &other) {
    if (this != &other) {
        stack_ = other.stack_;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::checkInput(const std::string &input) const 
{
    if (input.empty())
        throw std::invalid_argument("Input is empty");

    size_t i = 0;
    int numbers = 0;
    int operators = 0;
    bool wasToken = false;

    while (i < input.length()) 
    {
        if (isdigit(input[i])) {
            if (wasToken)
                throw std::invalid_argument("Missing space between tokens");
            numbers++;
            wasToken = true;
        }
        else if (input[i] == '+' || input[i] == '-' || 
                 input[i] == '*' || input[i] == '/') {
            if (wasToken)
                throw std::invalid_argument("Missing space between tokens");
            operators++;
            wasToken = true;
        }
        else if (input[i] == ' ')
            wasToken = false;
        else
            throw std::invalid_argument("Invalid character in input");
        i++;
    }

    if (operators != numbers - 1)
        throw std::invalid_argument("Mismatch between numbers and operators");

    return (true);
}

void    RPN::calculate(const std::string &input) {
    try {
        std::istringstream ss(input);
        std::string token;
        while (ss >> token) {
            if (isdigit(token[0])) {
                std::istringstream convert(token);
                double value;
                if (!(convert >> value))
                    throw std::invalid_argument("Invalid number format");
                pushToStack(value);
            } else if (token == "+") {
                add();
            } else if (token == "-") {
                subtract();
            } else if (token == "*") {
                multiply();
            } else if (token == "/") {
                divide();
            } else {
                throw std::invalid_argument("Invalid token in expression");
            }
        }
    } catch (const std::exception &e) {
        throw;
    }
}

void    RPN::pushToStack(double value) {
    stack_.push_back(value);
}

void    RPN::add() {
    double a = stack_.back();
    stack_.pop_back();
    double b = stack_.back();
    stack_.pop_back();
    double result = a + b;
    if ((a > 0 && b > 0 && result < 0) || (a < 0 && b < 0 && result > 0))
        throw std::overflow_error("Addition overflow");
    stack_.push_back(result);
}

void    RPN::subtract() {
    double a = stack_.back();
    stack_.pop_back();
    double b = stack_.back();
    stack_.pop_back();
    double result = b - a;
    if ((b > 0 && a < 0 && result < 0) || (b < 0 && a > 0 && result > 0))
        throw std::overflow_error("Subtraction overflow");
    stack_.push_back(result);
}

void    RPN::multiply() {
    double a = stack_.back();
    stack_.pop_back();
    double b = stack_.back();
    stack_.pop_back();
    double result = a * b;
    if (a != 0 && result / a != b)
        throw std::overflow_error("Multiplication overflow");
    stack_.push_back(result);
}

void    RPN::divide() {
    double a = stack_.back();
    stack_.pop_back();
    double b = stack_.back();
    stack_.pop_back();
    if (a == 0)
        throw std::runtime_error("Division by zero");
    double result = b / a;
    if (result == std::numeric_limits<double>::infinity() || result == -std::numeric_limits<double>::infinity())
        throw std::overflow_error("Division overflow");
    stack_.push_back(result);
}

void    RPN::printResult() const {
    if (stack_.size() == 1)
        std::cout << stack_.back() << std::endl;
}
