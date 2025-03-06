#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &other) {
    if (this != &other) {
        exchangeRates_ = other.exchangeRates_;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange () {}

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
        std::string rateStr;

        if (std::getline(ss, date, ',') && std::getline (ss, rateStr)) {
            date = trim(date);
            rateStr = trim(rateStr);

            bool validDate = validateDate(date);
            bool validRate = false;
            double rate = 0.0;

            std::istringstream rateStream(rateStr);
            if (rateStream >> rate && rateStream.eof()) {
                validRate = validateRate(rate);
            }

            if (validDate && validRate) {
                exchangeRates_[date] = rate;
            } else if (!validDate) {
                std::cerr << "Error: data.csv: invalid date in line: " << line << std::endl;
            } else if (!validRate) {
                std::cerr << "Error: data.csv: invalid rate in line: " << line << std::endl;
            }
        } else {
            std::cerr << "Error: data.csv: invalid formatting in line: " << line << std::endl;
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

void    BitcoinExchange::processLine(const std::string& line, const std::string& filename) const
{
    std::istringstream ss(line);
    std::string date;
    std::string amountStr;

    if (std::getline(ss, date, '|') && std::getline(ss, amountStr)) {
        date = trim(date);
        amountStr = trim(amountStr);

        bool validDate = validateDate(date);
        bool validAmount = false;
        double amount = 0.0;

        std::istringstream amountStream(amountStr);
        if (amountStream >> amount && amountStream.eof()) {
            validAmount = validateAmount(amount);
        }

        if (validDate && validAmount) {
            double result = calculate(exchangeRates_, date, amount);
            std::cout << date << "=> " << amount << " = " << result << std::endl;
        } else if (!validDate) {
                std::cerr << "Error: " << filename << ": invalid date in line: " << line << std::endl;
        } else if (!validAmount) {
            std::cerr << "Error: " << filename << ": invalid amount in line: " << line << std::endl;
        }
    } else {
        std::cerr << "Error: " << filename << ": invalid formatting in line: " << line << std::endl;
    }
}

void BitcoinExchange::readInput(std::string const filename) const
{
    std::ifstream input(filename.c_str());
    if (!input.is_open())
        throw std::runtime_error("Error: could not open " + filename);

    std::string line;
    if (std::getline(input, line)) {
        if (line.find("date") != std::string::npos && line.find("value") != std::string::npos) {
            ;
        }
        else {
            processLine(line, filename);
        }
    }

    while (std::getline(input, line)) {
        processLine(line, filename);
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
