#ifndef RPN_HPP
#define RPN_HPP

#include <deque>

class RPN
{
    private:
        std::deque<double> stack_;
        std::deque<double> result_;

    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator = (const RPN &other);
        ~RPN();
        
};

#endif