#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const Point &copy): _x(copy._x), _y(copy._y) {}

Point &Point::operator = (const Point &copy)
{
    if (this != &copy)
    {
        this->_x = copy._x;
        this->_y = copy._y;
    }
    return (*this);
}

Point(const float x, const float y);
~Point();