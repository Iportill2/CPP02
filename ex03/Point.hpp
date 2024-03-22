#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <string>

class Point
{
    public:
        Point(void);
        Point(float const value1, float const value2); // Duda Double/Int/Float???
        Point(const Point& other);
        Point &operator=(Point const &other);
        ~Point(void);

        Fixed getPosX(void) const;
        Fixed getPosY(void) const;

    private:
        const Fixed x;
        const Fixed y;
};


bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif