#include "Point.hpp"
#include "Fixed.hpp"

int main(){
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point point(-1, 1);

    if (bsp(a, b, c, point))
        std::cout << "The point is inside the triangle." << std::endl;
    else
        std::cout << "The point is outside the triangle." << std::endl;
    return (0);
}

