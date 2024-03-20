#ifndef	FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_fract = 8;
			
	public:
		Fixed(void);
		Fixed(const int i);
		Fixed(const float f);
		~Fixed(void);
		
		Fixed	(const Fixed &copy);
		Fixed &	operator=(Fixed const &inst2);
		
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const val);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif