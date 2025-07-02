#ifndef	FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
	public:
	//CANONICAL
		Fixed(void);
		Fixed(const int i);
		Fixed(const float f);
		Fixed	(const Fixed &copy);
		Fixed &	operator=(Fixed const &inst);
		~Fixed(void);
		
		
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const val);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif