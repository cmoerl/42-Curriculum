#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>

class   BitcoinExchange 
{
    private:
        std::map <std::string, double> exchangeRates_;

    public:
        BitcoinExchange();
        BitcoinExchange(std::string date, double exchangeRate); // Updated constructor
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator = (const BitcoinExchange &other);
        ~BitcoinExchange ();

        void addRate(const std::string& date, double rate);
        double getRate(const std::string& date) const;
        void display() const;

        const std::map<std::string, double>& getRates() const;

};

#endif