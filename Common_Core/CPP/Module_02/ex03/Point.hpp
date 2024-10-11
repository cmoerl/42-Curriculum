#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    public:
        Point();
        Point(const Point &copy);
        Point &operator = (const Point &copy);
        Point(const float x, const float y);
        ~Point();

    private:
        const Fixed _x;
        const Fixed _y;
};

#endif

bool bsp( Point const a, Point const b, Point const c, Point const point);