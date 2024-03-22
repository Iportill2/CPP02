#ifndef	FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
        int fixed_point;
        static const int fractional_bits = 8;
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
        
        bool operator>(const Fixed& fixed) const;
        bool operator<(const Fixed& fixed) const;
        bool operator>=(const Fixed& fixed) const;
        bool operator<=(const Fixed& fixed) const;
        bool operator==(const Fixed& fixed) const;
        bool operator!=(const Fixed& fixed) const;

        float operator+(const Fixed& fixed);
        float operator-(const Fixed& fixed);
        float operator*(const Fixed& fixed);
        float operator/(const Fixed& fixed);

        Fixed operator++(int);
        Fixed operator--(int);
        Fixed &operator++();
        Fixed &operator--();

        static Fixed& min(Fixed& num1, Fixed& num2);
        static const Fixed& min(const Fixed& num1, const Fixed& num2);
        static Fixed& max(Fixed& num1, Fixed& num2);
        static const Fixed& max(const Fixed& num1, const Fixed& num2);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif

