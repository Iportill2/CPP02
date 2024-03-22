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
    if (/* this-> */toFloat() > fixed.toFloat())
            return true;
    else
            return false;
};

bool    Fixed::operator<(const Fixed& fixed) const{
    if (/* this-> */toFloat() < fixed.toFloat())
            return true;
    else
            return false;
};

bool    Fixed::operator>=(const Fixed& fixed) const{
    if (/* this-> */toFloat() >= fixed.toFloat())
            return true;
    else
            return false;
};

bool    Fixed::operator<=(const Fixed& fixed) const{
    if (/* this-> */toFloat() <= fixed.toFloat())
            return true;
    else
            return false;
};

bool    Fixed::operator==(const Fixed& fixed) const{
    if (/* this-> */toFloat() == fixed.toFloat())
            return true;
    else
            return false;
};

bool    Fixed::operator!=(const Fixed& fixed) const{
    if (/* this-> */toFloat() != fixed.toFloat())
            return true;
    else
            return false;
};



float    Fixed::operator+(const Fixed& fixed){
    return (/* this-> */toFloat() + fixed.toFloat());
};

float    Fixed::operator-(const Fixed& fixed){
    return (/* this-> */toFloat() - fixed.toFloat());
};

float    Fixed::operator*(const Fixed& fixed){
    return (/* this-> */toFloat() * fixed.toFloat());
};

float    Fixed::operator/(const Fixed& fixed){
    if (fixed.fixed_point == 0)
        std::cout << "Division by 0 is not allowed" << std::endl;
    return (/* this-> */toFloat() / fixed.toFloat());
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
