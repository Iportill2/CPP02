#include "Point.hpp"

float	area(Point const a, Point const b, Point const c)
{
	//Float ABsolute Value
	return (std::fabs((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) 
					+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) 
					+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f));
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	/* Calculate area of tje triangle ABC */
	float triangleArea = area(a, b, c);
	std::cout << "Area of the triangle ABC: " << triangleArea << std::endl;
	
	/* Calculate area of tje triangle PBC */
	float areaPBC = area(point, b, c);
	std::cout << "Area of the triangle PBC: " << areaPBC << std::endl;
	
	/* Calculate area of tje triangle APC */
	float areaAPC = area(a, point, c);
	std::cout << "Area of the triangle APC: " << areaAPC << std::endl;
	
	/* Calculate area of tje triangle ABP */
	float areaABP = area(a, b, point);
	std::cout << "Area of the triangle ABP: " << areaABP << std::endl;

	if (a.getX() == point.getX() && a.getY() == point.getY())
		return (false);
	if (b.getX() == point.getX() && b.getY() == point.getY())
		return (false);
	if (c.getX() == point.getX() && c.getY() == point.getY())
		return (false);
	if (areaPBC == 0 || areaAPC == 0 || areaABP == 0)
		return (false);
	if(triangleArea == areaPBC + areaAPC + areaABP)
		return(true);
	return(false);
}