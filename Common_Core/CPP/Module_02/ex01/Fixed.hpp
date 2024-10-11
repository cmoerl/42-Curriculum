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

    private:

        int                 _value;
        static const int    _fractBits = 8;
};

std::ostream    &operator<<(std::ostream &out, const Fixed &fixed);

#endif
