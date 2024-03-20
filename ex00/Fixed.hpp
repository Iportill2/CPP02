#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
class Fixed
{
	private:

	int _value;
	static const int bits = 8;
/* ◦An integer to store the fixed-point number value.
◦A static constant integer to store the number of fractional bits. Its value
will always be the integer literal 8. */
	public:

	Fixed();
	~Fixed();

	Fixed	(const Fixed &copy);
	Fixed &	operator=(Fixed const &inst2);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	void endl_print(std::string s);


/* 	•Public members:
◦A default constructor that initializes the fixed-point number value to 0.//
◦A copy constructor.
◦A copy assignment operator overload.
◦A destructor.//
◦A member function int getRawBits( void ) const;//
that returns the raw value of the fixed-point value.//
◦A member function void setRawBits( int const raw );//
that sets the raw value of the fixed-point number.// */
};
#endif