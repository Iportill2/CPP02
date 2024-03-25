#include "Point.hpp"
#include "Fixed.hpp"

int main()
{
    Point a(-2, 2);
    Point b(0, 0);
    Point c(-2, -2);
    Point point(0, 0);

    if (bsp(a, b, c, point))
        std::cout << "The point is inside the triangle." << std::endl;
    else
        std::cout << "The point is outside the triangle." << std::endl;
return (1);
}

