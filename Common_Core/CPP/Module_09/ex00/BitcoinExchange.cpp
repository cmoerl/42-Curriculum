#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::cout << "BitcoinExchange default constructor called" << std::endl;
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

// NEEDS TO BE CHANGED ACCORDING TO SUBJECT
// void BitcoinExchange::display() const {
//     std::map<std::string, double>::const_iterator it;
//     for (it = exchangeRates_.begin(); it != exchangeRates_.end(); ++it) {
//         std::cout << it->first << ": " << it->second << std::endl;
//     }
// }

void    BitcoinExchange::setRates() 
{
    std::ifstream db("data.csv");
    if (!db.is_open())
        throw std::runtime_error("Error: could not open data.csv");

    std::string line;
    std::getline(db, line);

    while (std::getline(db, line)) {
        std::istringstream ss(line);
        std::string date;
        double rate;

        if (std::getline(ss, date, ',') && ss >> rate) {
            if (validateDate(date) && validateRate(rate)) {
                exchangeRates_[date] = rate;
            } else {
                std::cerr << "Error: invalid data in line: " << line << std::endl;
            }
        }
    }
    if (exchangeRates_.empty())
        throw std::runtime_error("Error: no valid data in data.csv");
}

bool BitcoinExchange::validateDate(std::string date) const
{
    if (date.length() != 10)
        return (false);
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            if (date[i] != '-')
                return (false);
        }
        else {
            if (!isdigit(date[i]))
                return (false);
        }
    }

    std::istringstream ssYear(date.substr(0, 4));
    std::istringstream ssMonth(date.substr(5, 2));
    std::istringstream ssDay(date.substr(8, 2));

    int year, month, day;
    ssYear >> year;
    ssMonth >> month;
    ssDay >> day;

    if (month < 1 || month > 12)
        return (false);

    int daysInMonth[] = { 31, (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (day < 1 || day > daysInMonth[month - 1])
        return (false);

    return (true);
}

bool BitcoinExchange::validateRate(double rate) const
{
    if (rate < 0)
        return (false);
    if (rate > DBL_MAX || rate == INFINITY || rate != rate)
        return (false);
    return (true);
}

bool    BitcoinExchange::validateAmount(double amount) const
{
    if (amount < 0 || amount > 1000)
        return (false);
    return (true);
}

std::string trim(const std::string& str) {
    std::string::const_iterator start = str.begin();
    while (start != str.end() && std::isspace(*start)) {
        ++start;
    }

    std::string::const_iterator end = str.end();
    do {
        --end;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}

void BitcoinExchange::readInput(std::string filename) const
{
    std::ifstream input(filename.c_str());
    if (!input.is_open())
        throw std::runtime_error("Error: could not open " + filename);

    std::string line;
    while (std::getline(input, line)) {
        std::istringstream ss(line);
        std::string date;
        double amount;

        if (std::getline(ss, date, '|') && ss >> amount) {
            date = trim(date);
            if (validateDate(date) && validateAmount(amount)) {
                double result = calculate(exchangeRates_, date, amount);
                std::cout << date << "=> " << amount << " = " << result << std::endl;
            } else {
                std::cerr << "Error: invalid data in line: " << line << std::endl;
            }
        }
    }
}

double  BitcoinExchange::calculate(std::map<std::string, double> rates, const std::string& date, double amount) const 
{
    if (date < "2009-01-02")
        return 0.0;
    std::map<std::string, double>::const_iterator it = rates.lower_bound(date);
    if (it == rates.end() || it->first != date) {
        if (it == rates.begin()) {
            throw std::runtime_error("Error: no exchange rate available for date " + date);
        }
        --it;
    }

    return (amount * it->second);
}
