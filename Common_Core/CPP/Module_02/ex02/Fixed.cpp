#include "Fixed.hpp"

Fixed::Fixed(): _value(0) {}

// initialises the new object
Fixed::Fixed(const Fixed &fixed) {
    this->_value = fixed._value;
}

// ensures that the object can be assigned from another object
Fixed& Fixed::operator=(const Fixed &fixed) {
    if (this != &fixed)
        this->_value = fixed._value;
    return (*this);
}

Fixed::Fixed(const int value) {
    this->_value = value << this->_fractBits;
}

Fixed::Fixed(const float value) {
    this->_value = roundf(value * (1 << this->_fractBits));
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const
{
    return (this->_value);
}

void    Fixed::setRawBits(int const raw)
{
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

Fixed            &Fixed::min(Fixed &a, Fixed &b)
{
    if (a > b)
        return (b);
    return (a);
}

const Fixed      &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (b);
    return (a);
}

Fixed            &Fixed::max(Fixed &a, Fixed &b)
{
    if (a < b)
        return (b);
    return (a);
}

const Fixed      &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (b);
    return (a);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed &cmp)const
{
    return (this->_value > cmp._value);
}

bool Fixed::operator<(const Fixed &cmp)const
{
    return(this->_value < cmp._value);
}

bool Fixed::operator>=(const Fixed &cmp)const
{
    return (this->_value >= cmp._value);
}

bool Fixed::operator<=(const Fixed &cmp)const
{
    return (this->_value <= cmp._value);
}

bool Fixed::operator==(const Fixed &cmp)const
{
    return (this->_value == cmp._value);
}

bool Fixed::operator!=(const Fixed &cmp)const
{
    return (this->_value != cmp._value);
}

Fixed   Fixed::operator+(const Fixed &fp)const
{
    Fixed result;

    result.setRawBits(this->_value + fp.getRawBits());
    return (result);
}

Fixed   Fixed::operator-(const Fixed &fp)const
{
    Fixed result;

    result.setRawBits(this->_value - fp.getRawBits());
    return (result);
}

Fixed   Fixed::operator*(const Fixed &fp)const
{
    Fixed result;

    result.setRawBits((this->_value * fp.getRawBits()) >> this->_fractBits);
    return (result);
}

Fixed   Fixed::operator/(const Fixed &fp)const
{
    Fixed result;

    if (fp._value == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return (Fixed());
    }
    result.setRawBits((this->_value << this->_fractBits) / fp.getRawBits());
    return (result);
}

Fixed   Fixed::operator--(int)
{
    Fixed   tmp = *this;

    this->_value--;
    return (tmp);
}

Fixed   Fixed::operator++(int)
{
    Fixed   tmp = *this;

    this->_value++;
    return (tmp);
}

Fixed   &Fixed::operator++()
{
    this->_value++;
    return (*this);
}

Fixed   &Fixed::operator--()
{
    this->_value--;
    return (*this);
}
