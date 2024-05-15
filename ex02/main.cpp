#include "Fixed.hpp"

void subject()
{
    std::cout << "[SUBJECT]" << std::endl;
    Fixed       a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

return;

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
    std::cout << "c.setRawBits(7)" << std::endl;
    std::cout << "c getRawBits:" << c.getRawBits() << std::endl;

    a.setRawBits(8);
    b.setRawBits(2);
    std::cout << "a.setRawBits(1) b.setRawBits(2);" << std::endl;
    std::cout << "a.getRawBits()=" << a.getRawBits() << std::endl <<  "b.getRawBits()=" << b.getRawBits() << std::endl;
    
    std::cout << "a._value:" << a.getRawBits() << std::endl;
    std::cout << "b._value:" << b.getRawBits() << std::endl;
    std::cout << "c._value:" << c.getRawBits() << std::endl;
    std::cout << "d._value:" << d.getRawBits() << std::endl;
    std::cout << "////////////" << std::endl;

    std::cout << "if a < b return :" << (a < b) << std::endl;
    std::cout << "if a > b return :" << a.operator>(b) << std::endl;
    std::cout << "if a <= b return :" << a.operator<=(b) << std::endl;
    std::cout << "if a >= b return :" << a.operator>=(b) << std::endl;
    std::cout << "if a == b return :" << a.operator==(b) << std::endl;
    std::cout << "if a != b return :" << a.operator!=(b) << std::endl;
    std::cout << "////////////" << std::endl;

    Fixed suma(0);
    Fixed resta(0);
    Fixed multi(0);
    Fixed divi(0);
    suma = a.getRawBits() + b.getRawBits();
    std::cout << "a + b =" << suma << std::endl;
    resta = a.getRawBits() - b.getRawBits();
    std::cout << "a - b =" << resta << std::endl;
    multi = a.getRawBits() * b.getRawBits();
    std::cout << "a * b =" << multi << std::endl;
    divi = a.getRawBits() / b.getRawBits();
    std::cout << "a / b =" << divi << std::endl;
    std::cout << "////////////" << std::endl;
    a.setRawBits(0);
    b.setRawBits(0);
    c.setRawBits(0);
    d.setRawBits(0);
    std::cout << "a._value:" << a.getRawBits() << std::endl;
    std::cout << "b._value:" << b.getRawBits() << std::endl;
    std::cout << "c._value:" << c.getRawBits() << std::endl;
    std::cout << "d._value:" << d.getRawBits() << std::endl;
    std::cout << "////////////" << std::endl;
    Fixed *operatorMmv1;
    Fixed operatorMmi1;
    Fixed *operatorMmv2;
    Fixed operatorMmi2;
    operatorMmv1=&a.operator++();
    operatorMmi1=b.operator++(4);
    operatorMmv2=&c.operator--();
    operatorMmi2=d.operator--(4);

    std::cout << "a._value:" << a.getRawBits() << std::endl;
    std::cout << "b._value:" << b.getRawBits() << std::endl;
    std::cout << "c._value:" << c.getRawBits() << std::endl;
    std::cout << "d._value:" << d.getRawBits() << std::endl;

    std::cout << "operatorMmv1=" << operatorMmv1->getRawBits() << std::endl;
    std::cout << "operatorMmi1=" << operatorMmi1.getRawBits() << std::endl;
    std::cout << "operatorMmv2=" << operatorMmv2->getRawBits() << std::endl;
    std::cout << "operatorMmi2=" << operatorMmi2.getRawBits() << std::endl;
    std::cout << "////////////" << std::endl;
    a.setRawBits(1);
    b.setRawBits(2);
    c.setRawBits(3);
    d.setRawBits(4);

    Fixed a1(1);
    Fixed b1(2);
    const Fixed a2(1);
    const Fixed b2(2);

    std::cout << "a1._value:" << a1 << std::endl;
    std::cout << "b1._value:" << b1 << std::endl;
    std::cout << "a2._value:" << a2 << std::endl;
    std::cout << "b2._value:" << b2 << std::endl;
    std::cout << "*********************" << std::endl;
    std::cout << Fixed::min(a1,b1) << std::endl;
    std::cout << Fixed::max(a1,b1)<< std::endl;
    std::cout << "*********************" << std::endl;
    std::cout << Fixed::min(a2,b2) << std::endl;
    std::cout << Fixed::max(a2,b2) << std::endl;
    std::cout << "*********************" << std::endl;
    a1.setRawBits(1);//(n *256) para obtener el valor
    b1.setRawBits(2);//(n *256) para obtener el valor
    //a2.setRawBits(3);//(n *256) para obtener el valor
    //b2.setRawBits(4);//(n *256) para obtener el valor

    std::cout << "a1._value:" << a1 << std::endl;
    std::cout << "b1._value:" << b1 << std::endl;
    std::cout << "a2._value:" << a2 << std::endl;
    std::cout << "b2._value:" << b2 << std::endl;
    std::cout << "////////////" << std::endl;
    std::cout << "a1._value:" << a1.getRawBits() << std::endl;
    std::cout << "b1._value:" << b1.getRawBits() << std::endl;
    std::cout << "a2._value:" << a2.getRawBits() << std::endl;
    std::cout << "b2._value:" << b2.getRawBits() << std::endl;


}

int main( void ) 
{
    std::cout << "----------------------------------------" << std::endl;
    subject();
    std::cout << "----------------------------------------" << std::endl;
    owntest();
    std::cout << "----------------------------------------" << std::endl;
} 


/*

$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
*/