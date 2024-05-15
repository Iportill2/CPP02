#include "Fixed.hpp"

//Default constructor
Fixed::Fixed(void): _value(0)
{
	//_value = 0;
	std::cout << "Default constructor called with 0" << std::endl;

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
	_value = i << _fract;
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
	_value = static_cast<int>(roundf(f * (1 << _fract)));
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
	_value = inst._value;
	return (*this);
}

/* 
	opposite to what the float contructor does
	converts the fixed to int (divides by 2^8)
*/
float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / (1 << _fract));
}

/* 
	opposite to what the int contructor does
	converts the fixed to int (divides by 2^8)
*/
int		Fixed::toInt(void) const
{
	return (_value >> _fract);
}

int		Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const val)
{
	_value = val;
}
std::ostream & operator<<(std::ostream & os, Fixed const & fixed)
{
	os << fixed.toFloat();
    return (os);
}