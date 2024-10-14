#include "Point.hpp"
#include "Fixed.hpp"

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

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::~Point() {}

Fixed    Point::getX() const
{
    return (_x);
}

Fixed   Point::getY() const
{
    return (_y);
}

void    Point::setX(Fixed const x)
{
    _x = x;
}

void    Point::setY(Fixed const y)
{
    _y = y;
}
