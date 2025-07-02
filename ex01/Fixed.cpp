#include "Fixed.hpp"

//Default constructor
Fixed::Fixed(void): _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/* 
	int constructor 
	not used an intialization list for clarity
	initialize the fixed instance with an int
	left shift _fract (8 bits)  
	same as multipling by 2^8
*/
Fixed::Fixed(const int i)
{
	this->_fixedPointValue = i << this->_fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

/*
	float constructor
	not used an intialization list for clarity
	initialize the fixed instance with a float
	left shift _fract (8 bits)  
	same as multipling by 2^8
*/
Fixed::Fixed(const float f)
{
	this->_fixedPointValue = static_cast<int>(roundf(f * (1 << _fractionalBits)));
	std::cout << "Float constructor called" << std::endl;
}

//Destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed &inst)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = inst;
}

//Assignation operator overload
Fixed &	Fixed::operator=(Fixed const &inst)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &inst)
		this->_fixedPointValue = inst.getRawBits();
	return (*this);
}

/* 
	opposite to what the float contructor does
	converts the fixed to int (divides by 2^8)
*/
float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const val)
{
	this->_fixedPointValue = val;
}
std::ostream & operator<<(std::ostream & os, Fixed const & fixed)
{
	os << fixed.toFloat();
    return (os);
}