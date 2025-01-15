#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./RPN <expression>" << std::endl;
        return (1);
    }

    RPN rpn;

    try {
        rpn.checkInput(argv[1]);
        rpn.calculate(argv[1]);
        rpn.printResult();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }

    return (0);
}
