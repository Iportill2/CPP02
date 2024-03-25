#include "Point.hpp"


bool bsp( const Point  a, const Point  b, const Point  c, const Point  point)
{
    Point d((b.getPosX() - a.getPosX()), (b.getPosY() - a.getPosY()));
    Point e(c.getPosX() - a.getPosX(), c.getPosY() - a.getPosY());
    float w1 = (e.getPosX() * (a.getPosY() - point.getPosY()) + e.getPosY() * (point.getPosX() - a.getPosX())) / (d.getPosX() * e.getPosY() - d.getPosY() * e.getPosX());
    float w2 = (point.getPosY() - a.getPosY() - (w1 * d.getPosY().toFloat())) / e.getPosY().toFloat();
    //fixed_point / (1<< fractional_bits));
    std::cout << w1 << std::endl;
    std::cout << w2 << std::endl;
    std::cout << w1+w2 << std::endl;

    if((w1 > 0.0) && (w2 > 0.0) && ((w1 + w2) < 1.0))
        return(true);
    else
    {
        std::cout << "ERROR" << std::endl;
        if(w1 <= 0.0)
            std::cout <<"w1=" << w1 << std::endl;
        if(w2 <= 0.0)
            std::cout << "w2=" << w2 << std::endl;
        if((w1 + w2) < 1.0)
            std::cout << "w1+w2=" << w1+w2 << std::endl;
        return(false);
    }
}
