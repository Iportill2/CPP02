#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <math.h>
class Fixed
{
	private:

		int _value;
		static const int bits = 8;

	public:
		Fixed();
		Fixed(const int parm);
		~Fixed();
		Fixed(const float nbr);

		Fixed &	operator=(Fixed const &inst);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		void endl_print(std::string s);

		float toFloat( void ) const;
		//that converts the fixed-point value to a floating-point value.
		int toInt( void ) const;
		//that converts the fixed-point value to an integer value
		/*
		And add the following function to the Fixed class files:
		•An overload of the insertion («) operator that inserts a floating-point representation
		of the fixed-point number into the output stream object passed as parameter.
		*/
};
#endif