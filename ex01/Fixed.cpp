#include "Fixed.hpp"

//Default constructor
Fixed::Fixed(void): _value(0)
{
	//_value = 0;
	endlprint("Default constructor called with 0");
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
	endlprint("Float constructor called");

}

//Destructor
Fixed::~Fixed(void)
{
	endlprint("Destructor called");
}

//Copy constructor
Fixed::Fixed(const Fixed &inst)
{
	endlprint("Copy constructor called");
	*this = inst;
}

//Assignation operator overload
Fixed &	Fixed::operator=(Fixed const &inst)
{
	endlprint("Assigment operator called");
	_value = inst.getRawBits();
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
void	Fixed::endlprint(std::string s)
{
	std::cout << s << std::endl;
}
std::ostream & operator <<(std::ostream & os, Fixed const & fixed)
{
	os << fixed.toFloat();
    return (os);
}