#ifndef RPN_HPP
#define RPN_HPP

#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <stdexcept>
#include <limits>

class RPN
{
    private:
        std::deque<double>  stack_;

    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator = (const RPN &other);
        ~RPN();

        bool    checkInput(const std::string &expression) const;
        void    calculate(const std::string &expression);
        void    printResult() const;

        void    pushToStack(double value);

        void    add();
        void    subtract();
        void    multiply();
        void    divide();
        
};

#endif
