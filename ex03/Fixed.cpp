#include "Fixed.hpp"

Fixed::Fixed(void)
{
    fixed_point = 0;
    //std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = other;
};

Fixed &Fixed::operator=(Fixed const &other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(other.getRawBits());
    return *this;
};

Fixed::~Fixed(void)
{
    //std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits( void ) const
{
    return (fixed_point);
};

void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;
};

Fixed::Fixed(const int value)
{
    //std::cout << "Int constructor called " << this->fixed_point << std::endl;
    setRawBits(value * (1<< fractional_bits));
};

Fixed::Fixed(const float value)
{
    //std::cout << "Float constructor called: " << this->fixed_point << std::endl;
    setRawBits(roundf(value * (1<< fractional_bits)));
};

float Fixed::toFloat( void ) const
{
    return (roundf(getRawBits()) / (1<< fractional_bits));
};

int Fixed::toInt( void ) const
{
    return (fixed_point / (1<< fractional_bits));
};



bool    Fixed::operator>(const Fixed& fixed) const{
    if (this->toFloat() > fixed.toFloat())
            return true;
    else
            return false;
};

bool    Fixed::operator<(const Fixed& fixed) const{
    if (this->toFloat() < fixed.toFloat())
            return true;
    else
            return false;
};

bool    Fixed::operator>=(const Fixed& fixed) const{
    if (this->toFloat() >= fixed.toFloat())
            return true;
    else
            return false;
};

bool    Fixed::operator<=(const Fixed& fixed) const{
    if (this->toFloat() <= fixed.toFloat())
            return true;
    else
            return false;
};

bool    Fixed::operator==(const Fixed& fixed) const{
    if (this->toFloat() == fixed.toFloat())
            return true;
    else
            return false;
};

bool    Fixed::operator!=(const Fixed& fixed) const{
    if (this->toFloat() != fixed.toFloat())
            return true;
    else
            return false;
};



float    Fixed::operator+(const Fixed& fixed){
    return (this->toFloat() + fixed.toFloat());
};

float    Fixed::operator-(const Fixed& fixed){
    return (this->toFloat() - fixed.toFloat());
};

float    Fixed::operator*(const Fixed& fixed){
    return (this->toFloat() * fixed.toFloat());
};

float    Fixed::operator/(const Fixed& fixed){
    if (fixed.fixed_point == 0)
        std::cout << "Division by 0 is not allowed" << std::endl;
    return (this->toFloat() / fixed.toFloat());
};



Fixed   Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
};

Fixed   Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
};

Fixed   &Fixed::operator++(){
    fixed_point += 1;
    return(*this);
};

Fixed   &Fixed::operator--(){
    fixed_point -= 1;
    return(*this);
};






Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
    if (num1 <= num2)
        return (num1);
    else
        return (num2);
};

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
    if (num1 <= num2)
        return (num1);
    else
        return (num2);
};

Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
    if (num1 >= num2)
        return (num1);
    else
        return (num2);
};

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
    if (num1 >= num2)
        return (num1);
    else
        return (num2);
};

//insertion operator overload
std::ostream & operator <<(std::ostream & os, Fixed const & fixed)
{
	os << fixed.toFloat();
    return (os);
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

