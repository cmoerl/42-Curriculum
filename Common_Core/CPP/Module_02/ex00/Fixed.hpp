#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed & operator = (const Fixed &fixed);
        ~Fixed();

        int     getRawBits() const;
        void    setRawBits(int const raw);

    private:

        int                 _value;
        static const int    _fractBits = 8;
};

#endif
