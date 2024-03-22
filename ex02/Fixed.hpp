#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <math.h>
class Fixed
{
	private:
		int 				_value;
		static const int	_fract = 8;
	public:
				Fixed();
				Fixed(float f);
				Fixed(const int i);
				~Fixed();
				
		void 	print(std::string s);
		float	toFloat()const;
		int		toInt()const;

		int		getRawBits(void) const;
		void	setRawBits(int const val);

		bool 	operator>(const	Fixed inst);
		bool 	operator<(const	Fixed inst);
		bool 	operator>=(const	Fixed inst);
		bool 	operator<=(const	Fixed inst);
		bool 	operator==(const	Fixed inst);
		bool 	operator!=(const	Fixed inst);

		Fixed	operator +(const Fixed& inst) const;
		Fixed	operator -(const Fixed& inst) const;
		Fixed	operator *(const Fixed& inst) const;
		Fixed	operator /(const Fixed& inst) const;

		Fixed&	operator++();		// pre-increment
		Fixed	operator++(int);	// post-increment
		Fixed&	operator--();		// pre-decrement
		Fixed	operator--(int);	// post-decrement

		static const Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b); 
};
std::ostream & operator<<(std::ostream & os, Fixed const & fixed);
#endif

