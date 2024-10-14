#include "Point.hpp"
#include <pthread.h>

void    printResult(bool result, std::string name)
{
    if (result == false)
        std::cout << name << " is outside of the triangle" << std::endl;
    else
        std::cout << name << " is inside the triangle" << std::endl;
}

int main()
{
    Point   triangle[] = {Point(3,8), Point(9,8), Point(3,2)};
    Point   point1 = Point(9,2);
    Point   point2 = Point(4, 6);
    Point   point3 = Point(3, 2);
    Point   point4 = Point(3.1, 2);
    Point   point5 = Point(3.1, 2.1);
    Point   point6 = Point(6, 8);
    Point   point7 = Point(0,0);
    bool    result1 = bsp(triangle[0], triangle[1], triangle[2], point1);
    printResult(result1, "point1");
    bool    result2 = bsp(triangle[0], triangle[1], triangle[2], point2);
    printResult(result2, "point2");
    bool    result3 = bsp(triangle[0], triangle[1], triangle[2], point3);
    printResult(result3, "point3");
    bool    result4 = bsp(triangle[0], triangle[1], triangle[2], point4);
    printResult(result4, "point4");
    bool    result5 = bsp(triangle[0], triangle[1], triangle[2], point5);
    printResult(result5, "point5");
    bool    result6 = bsp(triangle[0], triangle[1], triangle[2], point6);
    printResult(result6, "point6");
    bool    result7 = bsp(triangle[0], triangle[1], triangle[2], point7);
    printResult(result7, "point7");

    Point   triangle2[] = {Point(3,2), Point(3,6), Point(3,8)};
    Point   point8 = Point(3, 3);
    Point   point9 = Point(4, 4);
    Point   point10 = Point(-1,-1);
    bool    result8 = bsp(triangle2[0], triangle2[1], triangle2[2], point8);
    printResult(result8, "point8");
    bool    result9 = bsp(triangle2[0], triangle2[1], triangle2[2], point9);
    printResult(result9, "point9");
    bool    result10 = bsp(triangle2[0], triangle2[1], triangle2[2], point10);
    printResult(result10, "point10");
    return (0);
}
