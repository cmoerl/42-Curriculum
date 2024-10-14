#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <string>

class Point
{
    public:
        Point();
        Point(const Point &copy);
        Point &operator = (const Point &copy);
        Point(const float x, const float y);
        ~Point();

        void    setX(Fixed const x);
        void    setY(Fixed const y);
        Fixed   getX() const;
        Fixed   getY() const;

    private:
        Fixed _x;
        Fixed _y;
};

#endif

bool bsp( Point const a, Point const b, Point const c, Point const point);
