#include "Point.hpp"

Point::Point(void): x(0), y(0){}

Point::Point(float const x, float const y): x(x), y(y) {};


Point::Point(const Point& other): x(other.getPosX()), y(other.getPosY())
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

Fixed Point::getPosX(void) const {
    return x;
}

Fixed Point::getPosY(void) const {
    return y;
}