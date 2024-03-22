#ifndef	FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
        int 				fixed_point;
        static const int 	fractional_bits = 8;
    public:
        Fixed(void);
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        Fixed &operator=(Fixed const &other);
        ~Fixed(void);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        
        float operator+(const Fixed& fixed);
        float operator-(const Fixed& fixed);
        float operator*(const Fixed& fixed);
        float operator/(const Fixed& fixed);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif

