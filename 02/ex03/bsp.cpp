#include "Point.hpp"

Fixed area(Point const &a, Point const &b, Point const &c)
{
	 Fixed area = ((a.getX() * (b.getY() - c.getY()))
		+ (b.getX() * (c.getY() - a.getY()))
		+ (c.getX() * (a.getY() - b.getY()))) / Fixed(2);

	return (area > 0 ? area : area * -1);
}

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point)
{
	Fixed totalArea = area(a, b, c);
	Fixed area1 = area(point, a, b);
	Fixed area2 = area(point, b, c);
	Fixed area3 = area(point, c, a);
	return (totalArea == area1 + area2 + area3);
}