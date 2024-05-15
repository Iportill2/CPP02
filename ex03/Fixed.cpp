#include "Fixed.hpp"

Fixed::Fixed() //: _value(0)
{
	_value =0;

}
Fixed::Fixed(float f) : _value(static_cast<int>(roundf(f*(1 << _fract))))
{
	//_value = static_cast<int>(roundf(f*(1 << _fract)));
}
Fixed::Fixed(const int i)
{
	_value = i << _fract;
}
Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}
Fixed& Fixed::operator=(Fixed const &inst)
{
	_value = inst._value;
	return (*this);
}
Fixed::~Fixed()
{

}
////////////////////////////////////////////////////////

float Fixed::toFloat()const
{
	return(static_cast<float>(_value)/(1 << _fract));
}
int	Fixed::toInt()const
{
	return(_value >> _fract);
}
////////////////////////////////////////////////

int		Fixed::getRawBits(void) const
{
	return (this-> _value);
}

void	Fixed::setRawBits(int const val)
{
	this-> _value = val;
}
////////////////////////////////////////////////

bool 	Fixed::operator>(const	Fixed inst)
{
	if(this->_value > inst._value)
		return(true);
	else
		return(false);
}
bool 	Fixed::operator<(const	Fixed inst)
{
	if(this->_value < inst._value)
		return(true);
	else
		return(false);
}
bool 	Fixed::operator>=(const	Fixed inst)
{
	if(this->_value >= inst._value)
		return(true);
	else
		return(false);
}
bool 	Fixed::operator<=(const	Fixed inst)
{
	if(this->_value <= inst._value)
		return(true);
	else
		return(false);
}
bool 	Fixed::operator==(const	Fixed inst)
{
	if(this->_value == inst._value)
		return(true);
	else
		return(false);
}
bool 	Fixed::operator!=(const	Fixed inst)
{
	if(this->_value != inst._value)
		return(true);
	else
		return(false);
}
////////////////////////////////////////////////
Fixed	Fixed::operator +(const Fixed& inst) const
{
	Fixed	temp;

	temp.setRawBits((/* this-> */getRawBits() + inst.getRawBits()) / (1 << /* this-> */_fract));
	return (temp);
}
Fixed	Fixed::operator -(const Fixed& inst) const
{
	Fixed	temp;

	temp.setRawBits((/* this-> */getRawBits() - inst.getRawBits()) / (1 << /* this-> */_fract));
	return (temp);
}
Fixed	Fixed::operator *(const Fixed& inst) const
{
	Fixed	temp;

	temp.setRawBits((/* this-> */getRawBits() * inst.getRawBits()) / (1 << /* this-> */_fract));
	return (temp);
}
Fixed	Fixed::operator /(const Fixed& inst) const
{
	if (inst._value == 0)
		std::cout << "Zero division error" << std::endl;
	Fixed	temp;

	temp.setRawBits((/* this-> */getRawBits() / inst.getRawBits()) / (1 << /* this-> */_fract));
	return (temp);
}
/////////////////////////////////////////////////////////////////////////

Fixed &	Fixed::operator ++()		// pre-increment
{
	++this->_value;
	return (*this);
}

/* 
	1 create a copy of the actual object (via copy constructor)
	2 increments the value of the actual object
	3 returns a the copy of object that hasn´t been incremented
*/
Fixed	Fixed::operator ++(int)
{
	Fixed	tmp(*this);				//post-increment
	
	++this->_value;
	return (tmp);
}

Fixed &	Fixed::operator --()		// pre-decrement
{
	--this->_value;
	return (*this);
}

Fixed	Fixed::operator --(int)
{
	Fixed	tmp(*this);				//post-decrement
	
	--this->_value;
	return (tmp);
}
/////////////////////////////////////////////////////////////////////////

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if(a < b)
		return(a);
	else
		return(b);

}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if(a > b)
		return(a);
	else
		return(b);

}
const Fixed& Fixed::min(Fixed const& a, Fixed const& b)
{
	if(a._value < b._value)
		return(a);
	else
		return(b);

}
const Fixed& Fixed::max(Fixed const& a, Fixed const& b)
{
	if(a._value > b._value)
		return(a);
	else
		return(b);

}
std::ostream & operator<<(std::ostream & os, Fixed const & fixed)
{
	os << fixed.toFloat();
	return(os);
}