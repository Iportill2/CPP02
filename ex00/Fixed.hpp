#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
class Fixed
{
	private:

		int _value ;
		static const int _bits = 8;

	public:

					Fixed();
					Fixed	(const Fixed &copy);
		Fixed &		operator=(Fixed const &inst);
					~Fixed();
		int 		getRawBits( void ) const;
		void 		setRawBits( int const raw );
		void 		print(std::string s);

};
#endif