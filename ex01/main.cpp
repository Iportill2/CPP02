#include "Fixed.hpp"
void subject()
{
    Fixed       a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}
void owntest()
{
    std::cout << "[OWN TEST]" << std::endl;
    Fixed a;
    Fixed b (0.10f);
    Fixed c(1);
    std::cout << "////////////" << std::endl;
    std::cout << "a:" << a << std::endl;
    std::cout << "b:" << b << std::endl;
    std::cout << "c:" << c << std::endl;
    Fixed d(b);
    a = c;
    std::cout << "////////////" << std::endl;
    std::cout << "a:" << a << std::endl;
    std::cout << "b:" << b << std::endl;
    std::cout << "c:" << c << std::endl;
    std::cout << "d:" << d << std::endl;
    std::cout << "////////////" << std::endl;

    std::cout << "a to int:" << a.toFloat() << std::endl;
    std::cout << "b to float:" << b.toInt() << std::endl;

    std::cout << "c getRawBits:" << c.getRawBits() << std::endl;
    c.setRawBits(7);
    std::cout << "c.setRawBits:" << std::endl;
    std::cout << "c getRawBits:" << c.getRawBits() << std::endl;

    a.setRawBits(8);
    b.setRawBits(2);
    std::cout << "a.setRawBits(8) b.setRawBits(2);" << std::endl;
    std::cout << "a.getRawBits()=" << a.getRawBits() << std::endl <<  "b.getRawBits()=" << b.getRawBits() << std::endl;
    
    std::cout << "a._value:" << a.getRawBits() << std::endl;
    std::cout << "b._value:" << b.getRawBits() << std::endl;
    std::cout << "c._value:" << c.getRawBits() << std::endl;
    std::cout << "d._value:" << d.getRawBits() << std::endl;
    std::cout << "////////////" << std::endl;
}
int main( void ) 
{
    subject();
    owntest();

return(0);
}

/*

$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>
*/