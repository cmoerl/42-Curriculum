#include "Point.hpp"

Fixed   area(Point const &p1, Point const &p2, Point const &p3)
{
    float determinant = (p1.getX() * (p2.getY() - p3.getY()) +
                    p2.getX() * (p3.getY() - p1.getY()) +
                    p3.getX() * (p1.getY() - p2.getY())).toFloat();
    return (Fixed(determinant < 0 ? -determinant : determinant) / 2.0f);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    // area of triangle
    Fixed   areaABC = area(a, b, c);
    // sub-triangles made up of Point and the three sides
    Fixed   areaPAB = area(point, a, b);
    Fixed   areaPBC = area(point, b, c);
    Fixed   areaPCA = area(point, c, a);
    // check if sum of sub-triangles equals area of the triangle
    return (areaABC == (areaPAB + areaPBC + areaPCA) && areaPAB != 0 && areaPBC != 0 && areaPCA != 0);
}
