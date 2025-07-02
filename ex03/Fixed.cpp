#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
}

Fixed::Fixed(float f) : _fixedPointValue(static_cast<int>(roundf(f*(1 << _fractionalBits))))
{
}

Fixed::Fixed(const int i)
{
	this->_fixedPointValue = i << _fractionalBits;
}
Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}
Fixed& Fixed::operator=(Fixed const &inst)
{
	if (this != &inst)
		this->_fixedPointValue = inst.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}

float Fixed::toFloat()const
{
	return(static_cast<float>(this->_fixedPointValue)/(1 << this->_fractionalBits));
}

int	Fixed::toInt()const
{
	return(this->_fixedPointValue >> this->_fractionalBits);
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const val)
{
	this->_fixedPointValue = val;
}
////////////////////////////////////////////////

bool 	Fixed::operator>(const	Fixed inst)
{
	return (this->_fixedPointValue > inst._fixedPointValue);
}

bool 	Fixed::operator<(const	Fixed inst)
{
	return (this->_fixedPointValue < inst._fixedPointValue);
}

bool 	Fixed::operator>=(const	Fixed inst)
{
	return (this->_fixedPointValue >= inst._fixedPointValue);
}

bool 	Fixed::operator<=(const	Fixed inst)
{
	return (this->_fixedPointValue <= inst._fixedPointValue);
}

bool 	Fixed::operator==(const	Fixed inst)
{
	return (this->_fixedPointValue == inst._fixedPointValue);
}

bool 	Fixed::operator!=(const	Fixed inst)
{
	return (this->_fixedPointValue != inst._fixedPointValue);
}
////////////////////////////////////////////////
Fixed	Fixed::operator +(const Fixed& inst) const
{
	Fixed	temp;
	temp.setRawBits(this->getRawBits() + inst.getRawBits());
	return (temp);
}

Fixed	Fixed::operator -(const Fixed& inst) const
{
	Fixed	temp;
	temp.setRawBits(this->getRawBits() - inst.getRawBits());
	return (temp);
}

Fixed	Fixed::operator *(const Fixed& inst) const
{
	Fixed	temp;
	temp.setRawBits((this->getRawBits() * inst.getRawBits()) >> this->_fractionalBits);
	return (temp);
}

Fixed	Fixed::operator /(const Fixed& inst) const
{
	if (inst._fixedPointValue == 0)
		std::cout << "Zero division error" << std::endl;
	Fixed	temp;
	temp.setRawBits((this->getRawBits() << this->_fractionalBits) / inst.getRawBits());
	return (temp);
}
/////////////////////////////////////////////////////////////////////////

Fixed &	Fixed::operator ++()		// pre-increment
{
	++this->_fixedPointValue;
	return (*this);
}

Fixed	Fixed::operator ++(int)	// post-increment
{
	Fixed	tmp(*this);
	++this->_fixedPointValue;
	return (tmp);
}

Fixed &	Fixed::operator --()		// pre-decrement
{
	--this->_fixedPointValue;
	return (*this);
}

Fixed	Fixed::operator --(int)	// post-decrement
{
	Fixed	tmp(*this);
	--this->_fixedPointValue;
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
	if(a._fixedPointValue < b._fixedPointValue)
		return(a);
	else
		return(b);
}

const Fixed& Fixed::max(Fixed const& a, Fixed const& b)
{
	if(a._fixedPointValue > b._fixedPointValue)
		return(a);
	else
		return(b);
}
std::ostream & operator<<(std::ostream & os, Fixed const & fixed)
{
	os << fixed.toFloat();
	return(os);
}