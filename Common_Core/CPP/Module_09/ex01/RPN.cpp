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
    if (input.empty() || input.size() < 3)
        throw std::invalid_argument("Input is empty or too short");

    size_t i = 0;
    int numbers = 0;
    int operators = 0;

    while (i < input.length()) 
    {
        if (isdigit(input[i]))
            numbers++;
        else if (input[i] == '+' || input[i] == '-' || 
                 input[i] == '*' || input[i] == '/')
            operators++;
        else if (input[i] != ' ')
            throw std::invalid_argument("Invalid character in input");
        i++;
    }

    if (numbers < 2)
        throw std::invalid_argument("Not enough numbers in input");
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
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void    RPN::pushToStack(double value) {
    stack_.push_back(value);
}

void    RPN::add() {
    if (stack_.size() < 2)
        throw std::runtime_error("Not enough operands for addition");
    double a = stack_.back();
    stack_.pop_back();
    double b = stack_.back();
    stack_.pop_back();
    stack_.push_back(a + b);
}

void    RPN::subtract() {
    if (stack_.size() < 2)
        throw std::runtime_error("Not enough operands for subtraction");
    double a = stack_.back();
    stack_.pop_back();
    double b = stack_.back();
    stack_.pop_back();
    stack_.push_back(b - a);
}

void    RPN::multiply() {
    if (stack_.size() < 2)
        throw std::runtime_error("Not enough operands for multiplication");
    double a = stack_.back();
    stack_.pop_back();
    double b = stack_.back();
    stack_.pop_back();
    stack_.push_back(a * b);
}

void    RPN::divide() {
    if (stack_.size() < 2)
        throw std::runtime_error("Not enough operands for division");
    double a = stack_.back();
    stack_.pop_back();
    double b = stack_.back();
    stack_.pop_back();
    if (a == 0)
        throw std::runtime_error("Division by zero");
    stack_.push_back(b / a);
}

void    RPN::printResult() const {
    if (stack_.size() == 1)
        std::cout << stack_.back() << std::endl;
    else
        std::cerr << "Error: invalid expression" << std::endl;
}
