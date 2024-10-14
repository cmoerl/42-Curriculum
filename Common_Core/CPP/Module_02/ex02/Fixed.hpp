#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <ostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed & operator = (const Fixed &fixed);
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();

        int     getRawBits() const;
        void    setRawBits(int const raw);
        float   toFloat() const;
        int     toInt() const;

        static Fixed            &min(Fixed &a, Fixed &b);
        static const Fixed      &min(const Fixed &a, const Fixed &b);
        static Fixed            &max(Fixed &a, Fixed &b);
        static const Fixed      &max(const Fixed &a, const Fixed &b);

        bool operator>(const Fixed &cmp)const;
        bool operator<(const Fixed &cmp)const;
        bool operator>=(const Fixed &cmp)const;
        bool operator<=(const Fixed &cmp)const;
        bool operator==(const Fixed &cmp)const;
        bool operator!=(const Fixed &cmp)const;

        Fixed   operator+(const Fixed &fp)const;
        Fixed   operator-(const Fixed &fp)const;
        Fixed   operator*(const Fixed &fp)const;
        Fixed   operator/(const Fixed &fp)const;

        // post de- and increment
        Fixed   operator++(int);
        Fixed   operator--(int);
        // pre de- and increment
        Fixed   &operator++();
        Fixed   &operator--();

    private:

        int                 _value;
        static const int    _fractBits = 8;
};

std::ostream    &operator<<(std::ostream &out, const Fixed &fixed);

#endif
