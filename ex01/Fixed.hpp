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
		Fixed &	operator=(Fixed const &inst);
		
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const val);
		void	print(std::string s);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif