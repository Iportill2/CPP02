#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
class Fixed
{
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
	public:
	//CANONICAL
					Fixed();
					Fixed	(const Fixed &copy);
		Fixed &		operator=(Fixed const &inst);
					~Fixed();

		int 		getRawBits( void ) const;
		void 		setRawBits( int const raw );
};
#endif