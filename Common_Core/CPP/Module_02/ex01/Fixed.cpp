#include "Fixed.hpp"

Fixed::Fixed(): _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// initialises the new object
Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    this->_value = fixed._value;
}

// ensures that the object can be assigned from another object
Fixed& Fixed::operator=(const Fixed &fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->_value = fixed._value;
    return (*this);
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << this->_fractBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << this->_fractBits));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

float   Fixed::toFloat() const
{
    return (static_cast<float>(this->_value) / (1 << this->_fractBits));
}

int Fixed::toInt() const
{
    return (static_cast<int>(_value >> this->_fractBits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}
