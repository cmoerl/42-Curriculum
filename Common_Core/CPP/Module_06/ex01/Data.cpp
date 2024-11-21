#include "Data.hpp"

Data::Data() : number_(0) {
    std::cout << "Data default constructor" << std::endl;
}

Data::Data(const Data &copy) {
    *this = copy;
    std::cout << "Data copy constructor" << std::endl;
}

Data &Data::operator=(const Data &copy) {
    number_ = copy.number_;
    std::cout << "Data copy assigment operator" << std::endl;
    return (*this);
}

Data::~Data() {
    std::cout << "Data destructor" << std::endl;
}

int Data::getNumber() const {
    return (number_);
}

void Data::setNumber(int number) {
    number_ = number;
}
