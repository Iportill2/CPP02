#include "Point.hpp"

Point::Point(void): x(0), y(0){}

Point::Point(float const x, float const y): x(x), y(y) {};


Point::Point(const Point& other): x(other.getX()), y(other.getY())
{}

Point &Point::operator=(Point const &other)
{
	(void)other;
    //std::cout << "Copy assignment operator called" << std::endl;
    return *this;
};

Point::~Point(void)
{
    //std::cout << "Destructor called" << std::endl;
};

Fixed Point::getX(void) const {
    return x;
}

Fixed Point::getY(void) const {
    return y;
}