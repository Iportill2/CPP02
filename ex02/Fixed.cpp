#include "Fixed.hpp"

Fixed::Fixed() //: _value(0)
{
	_value =0;
	//print("Default Constructor");
}
Fixed::Fixed(float f) : _value(static_cast<int>(roundf(f*(1 << _fract))))
{
	//_value = static_cast<int>(roundf(f*(1 << _fract)));
}
Fixed::Fixed(const int i)
{
	_value = i << _fract;
}
Fixed::~Fixed()
{
	//print("Default Destructor");
}
void Fixed::print(std::string s)
{
	std::cout << s << std::endl;
}
float Fixed::toFloat()const
{
	return(static_cast<float>(_value)/(1 << _fract));
}
int	Fixed::toInt()const
{
	return(_value >> _fract);
}
std::ostream & operator<<(std::ostream & os, Fixed const & fixed)
{
	os << fixed.toFloat();
	return(os);
}
int		Fixed::getRawBits(void) const
{
	return (/* this-> */_value);
}

void	Fixed::setRawBits(int const val)
{
	/* this-> */_value = val;
}
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

