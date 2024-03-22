#include "Fixed.hpp"

Fixed::Fixed()
{
	_value =0;
	print("default constructor");
}
Fixed::Fixed(float f)
{
	_value = static_cast<int>(roundf(f*(1 << _fract)));
}
Fixed::Fixed(const int i)
{
	_value = i << _fract;
}
Fixed::~Fixed()
{

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
	return (this->_value);
}

void	Fixed::setRawBits(int const val)
{
	this->_value = val;
}
/* void Fixed::setRawBits(int i)
{
	_value=i;
}
int	Fixed::getRawBits()
{
	return(_value);
} */

bool	Fixed::operator>(const	Fixed inst)
{
	if(this->_value > inst._value)
		return(1);//TRUE
	else
		return (0);//FALSE
}
bool	Fixed::operator<(const	Fixed inst)
{
	if(this->_value < inst._value)
		return(1);//TRUE
	else
		return (0);//FALSE
}
bool	Fixed::operator>=(const	Fixed inst)
{
	if(this->_value >= inst._value)
		return(1);//TRUE
	else
		return (0);//FALSE
}
bool	Fixed::operator<=(const	Fixed inst)
{
	if(this->_value <= inst._value)
		return(1);//TRUE
	else
		return (0);//FALSE
}
bool	Fixed::operator==(const	Fixed inst)
{
	if(this->_value == inst._value)
		return(1);//TRUE
	else
		return (0);//FALSE
}
bool	Fixed::operator!=(const	Fixed inst)
{
	if(this->_value != inst._value)
		return(1);//TRUE
	else
		return (0);//FALSE
}

Fixed	Fixed::operator +(const Fixed& inst2) const
{
	Fixed	temp;

	temp.setRawBits((this->getRawBits() + inst2.getRawBits()) / (1 << this->_fract));
	return (temp);
}
Fixed	Fixed::operator -(const Fixed& inst2) const
{
	Fixed	temp;

	temp.setRawBits((this->getRawBits() - inst2.getRawBits()) / (1 << this->_fract));
	return (temp);
}
Fixed	Fixed::operator *(const Fixed& inst2) const
{
	Fixed	temp;

	temp.setRawBits((this->getRawBits() * inst2.getRawBits()) / (1 << this->_fract));
	return (temp);
}
Fixed	Fixed::operator /(const Fixed& inst2) const
{
	if (inst2._value == 0)
		std::cout << "Zero division error" << std::endl;
	Fixed	temp;

	temp.setRawBits((this->getRawBits() / inst2.getRawBits()) / (1 << this->_fract));
	return (temp);
}
Fixed &	Fixed::operator ++()		// pre-increment
{
	++this->_value;
	return (*this);
}
Fixed	Fixed::operator ++(int)
{
	Fixed	tmp(*this);				//post-increment
	
	++this->_value;
	return (tmp);
}
Fixed  & Fixed::operator--()
{
	--this->_value;
	return(*this);

}
Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	--this->_value;
	return(tmp);
}
const Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if( a.getRawBits() < b.getRawBits())
        return a;
    else
        return b;
	//return (a.getRawBits() < b.getRawBits() ? a : b);
}
const Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if(a.getRawBits() > b.getRawBits())
        return a;
    else
        return b;
	//return (a.getRawBits() > b.getRawBits() ? a : b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if( a.getRawBits() < b.getRawBits())
        return a;
    else
        return b;
	//return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if(a.getRawBits() > b.getRawBits())
        return a;
    else
        return b;
	//return (a.getRawBits() > b.getRawBits() ? a : b);
} 





































/*
#include "Fixed.hpp"

//Default constructor
Fixed::Fixed(void): _value(0)
{
	//std::cout << "Default constructor called with 0" << std::endl;
}


Fixed::Fixed(const int i)
{
	this->_value = i << this->_fract;
	//std::cout << "Int constructor called" << std::endl;
}


Fixed::Fixed(const float f)
{
	this->_value = static_cast<int>(roundf(f * (1 << this->_fract)));
	//std::cout << "Float constructor called" << std::endl;
}

//Destructor
Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed &inst)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = inst;
}

//Assignation operator overload
Fixed &	Fixed::operator=(Fixed const &inst)
{
	//std::cout << "Assigment operator called" << std::endl;
	this->_value = inst.getRawBits();
	return (*this);
}


float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << this->_fract));
}

/
int		Fixed::toInt(void) const
{
	return (this->_value >> this->_fract);
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const val)
{
	this->_value = val;
}

//comparison operators
bool	Fixed::operator >(const	Fixed &inst2)
{
	return (this->_value > inst2._value);
}

bool	Fixed::operator <(const	Fixed &inst2)
{
	return (this->_value < inst2._value);
}

bool	Fixed::operator >=(const	Fixed &inst2)
{
	return (this->_value >= inst2._value);
}

bool	Fixed::operator <=(const	Fixed &inst2)
{
	return (this->_value <= inst2._value);
}

bool	Fixed::operator ==(const	Fixed &inst2)
{
	return (this->_value == inst2._value);
}

bool	Fixed::operator !=(const	Fixed &inst2)
{
	return (this->_value != inst2._value);
}

//arithmetic operators

Fixed	Fixed::operator +(const Fixed& inst2) const
{
	Fixed	temp;

	temp.setRawBits((this->getRawBits() + inst2.getRawBits()) / (1 << this->_fract));
	return (temp);
}

Fixed	Fixed::operator -(const Fixed& inst2) const
{
	Fixed	temp;

	temp.setRawBits((this->getRawBits() - inst2.getRawBits()) / (1 << this->_fract));
	return (temp);
}

Fixed	Fixed::operator *(const Fixed& inst2) const
{
	Fixed	temp;

	temp.setRawBits((this->getRawBits() * inst2.getRawBits()) / (1 << this->_fract));
	return (temp);
}

Fixed	Fixed::operator /(const Fixed& inst2) const
{
	if (inst2._value == 0)
		std::cout << "Zero division error" << std::endl;
	Fixed	temp;

	temp.setRawBits((roundf(this->getRawBits()) / inst2.getRawBits()) * (1 << this->_fract));
	return (temp);
}

//increment / decrement operators


Fixed &	Fixed::operator ++()		// pre-increment
{
	++this->_value;
	return (*this);
}


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


const Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

//insertion operator overload
std::ostream & operator <<(std::ostream & os, Fixed const & fixed)
{
	os << fixed.toFloat();
    return (os);
}




*/

