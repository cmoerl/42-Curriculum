#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string date, double exchangeRate) {
    exchangeRates_[date] = exchangeRate;
    std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &other) {
    std::cout << "BitcoinExchange assignment operator called" << std::endl;
    if (this != &other) {
        exchangeRates_ = other.exchangeRates_;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange () {
    std::cout << "BitcoinExchange destructor called" << std::endl;
}

void BitcoinExchange::addRate(const std::string& date, double rate) {
    exchangeRates_[date] = rate;
}

double BitcoinExchange::getRate(const std::string& date) const {
    return exchangeRates_.at(date);
}
void BitcoinExchange::display() const {
    for (const auto& rate : exchangeRates_) {
        std::cout << rate.first << ": " << rate.second << std::endl;
    }
}

const std::map<std::string, double>& BitcoinExchange::getRates() const {
    return exchangeRates_;
}
