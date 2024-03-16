#include "Point.hpp"

Point::Point()
{
}

Point::Point(const float x, const float y) : x(x), y(y) 
{
}

Point::Point(const Point &point) 
{
	*this = point;
}

Point::~Point() 
{
}

Point &Point::operator=(const Point &point) 
{
	(void)point;
	return *this;
}

Fixed Point::getX( void ) const
{
	return this->x;
}

Fixed Point::getY(void) const
{
	return y;
}


