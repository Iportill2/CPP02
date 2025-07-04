#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <string>

class Point
{
    public:
        Point(void);
        Point(float const value1, float const value2);
        Point(const Point& other);
        ~Point(void);

        Fixed getX(void) const;
        Fixed getY(void) const;

    private:
        const Fixed x;
        const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif