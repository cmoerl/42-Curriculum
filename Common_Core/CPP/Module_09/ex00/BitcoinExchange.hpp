#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include <cfloat>
#include <cmath>

class   BitcoinExchange 
{
    private:
        std::map <std::string, double> exchangeRates_;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator = (const BitcoinExchange &other);
        ~BitcoinExchange ();


        void    setRates();
        double  calculate(std::map<std::string, double> rates, const std::string& date, double amount) const;
        void    readInput(std::string filename) const;
        void    display() const;


        bool validateDate(std::string date) const;
        bool validateRate(double rate) const;
        bool validateAmount(double amount) const;
};

#endif
