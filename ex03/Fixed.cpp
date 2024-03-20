#include "Fixed.hpp"

Fixed::Fixed()//
{
	endl_print("Default constructor called");
	_value = 0;
}

Fixed::Fixed(const int parm)//
{
	endl_print("Default constructor called");
	_value = 0;
}
Fixed::~Fixed()//
{
	endl_print("Destructor called");
}
Fixed::Fixed(const float nbr)//
{
	/*Para implementar este constructor, necesitamos convertir el número de punto flotante a un número de punto fijo. Esto se puede hacer multiplicando el número de punto flotante por 2 elevado a la cantidad de bits fraccionales (en este caso, 8) y luego redondeando al entero más cercano. Aquí está el código en C++:

_value = roundf(parm * (1 << bits));
Este código multiplica el número de punto flotante parm por 2 a la potencia de bits (que es 8), luego redondea al entero más cercano usando la función roundf. El resultado se almacena en _value, que es la representación de punto fijo del número.
	_value = roundf(nbr * (1 << bits));*/
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

