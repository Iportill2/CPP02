#include "Fixed.hpp"

Fixed::Fixed()
{
	endl_print("Default constructor called");
	_value = 0;
}
Fixed::~Fixed()
{
	endl_print("Destructor called");
}
Fixed::Fixed(const Fixed &inst)
{
	endl_print("Copy constructor called");
	std::cout << "Copy constructor called: Before: " << /* this-> */_value << " After: " << "//" << inst.getRawBits() <<"//" << std::endl;
	*this = inst;
}
Fixed & Fixed::operator=(Fixed const &inst)
{
	//std::cout << "Assigment operator called from " << this->_value;
	//std::cout << " to //" << inst.getRawBits() << "//" << std::endl;
	this->_value = inst.getRawBits();
	return (*this);

	/* (void)&inst2;
	endl_print("Copy assignment operator called");
	return (*this); */
}
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}
void Fixed::setRawBits( int const raw )
{
	/* this-> */_value = raw;
	//(void)raw;
}
void Fixed::endl_print(std::string s)
{
	std::cout << s << std::endl;	
}

/*
//Default constructor
Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called with 0" << std::endl;
}

//Destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed &inst)
{
	std::cout << "Copy constructor called: Before: " << this->_value << " After: " << "//" << inst.getRawBits() <<"//" << std::endl;
	*this = inst;
}

//Assignation operator overload
Fixed &	Fixed::operator=(Fixed const &inst)
{
	std::cout << "Assigment operator called from " << this->_value;
	std::cout << " to //" << inst.getRawBits() << "//" << std::endl;
	this->_value = inst.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called ";
	return (this->_value);
}

void	Fixed::setRawBits(int const val)
{
	this->_value = val;
}
*/