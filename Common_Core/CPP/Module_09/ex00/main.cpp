#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return (1);
    }

    BitcoinExchange exchangeRates;

    try {
        exchangeRates.setRates();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    try {
        exchangeRates.readInput(argv[1]);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}
