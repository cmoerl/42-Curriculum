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
#include <algorithm>
#include <cctype>
#include <stdexcept>

class   BitcoinExchange 
{
    private:
        std::map <std::string, double> exchangeRates_;

        double  calculate(std::map<std::string, double> rates, const std::string& date, double amount) const;
        void    processLine(const std::string& line, const std::string& filename) const;

        bool validateDate(std::string date) const;
        bool validateRate(double rate) const;
        bool validateAmount(double amount) const;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator = (const BitcoinExchange &other);
        ~BitcoinExchange ();

        void    setRates();
        void    readInput(std::string filename) const;

};

#endif
