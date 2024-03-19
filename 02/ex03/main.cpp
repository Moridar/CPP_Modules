#include "Point.hpp"

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point);

int main( void ) 
{
	Point a(0, 0);
	Point b(10, 29.987654321f);
	Point c(20, 0);
	Point p1(10, -0.005f);
	Point p2(10, 30.005f);

	std::cout << "b = " << b.getX() << ", " << b.getY() << std::endl;

	if (bsp(a, b, c, p1))
		std::cout << "p1 is inside the triangle" << std::endl;
	else
		std::cout << "p1 is outside the triangle" << std::endl;
	if (bsp(a, b, c, p2))
		std::cout << "p2 is inside the triangle" << std::endl;
	else
		std::cout << "p2 is outside the triangle" << std::endl;
return 0;
}
