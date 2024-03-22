#include "Fixed.hpp"

Fixed::Fixed()
{
	print("Default constructor called");
	_value = 0;
}
Fixed::Fixed(const Fixed &copy)
{
	print("Copy constructor called");
	*this = copy;
}
Fixed & Fixed::operator=(Fixed const &inst)
{
	print("Copy assignment operator called");
	_value = inst.getRawBits();
	return (*this);
}
Fixed::~Fixed()
{
	print("Destructor called");
}
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}
void Fixed::setRawBits( int const raw )
{
	_value = raw;
}
void Fixed::print(std::string s)
{
	std::cout << s << std::endl;	
}
