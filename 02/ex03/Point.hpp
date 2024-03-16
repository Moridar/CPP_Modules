#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &point);
		~Point();
		Point &operator=(const Point &point);
		Fixed getX(void) const;
		Fixed getY(void) const;
};
#endif