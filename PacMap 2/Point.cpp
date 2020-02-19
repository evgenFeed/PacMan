#include "Point.h"

Point& Point::operator+=(const Point& rValue)
{
	_x += rValue._x;
	_y += rValue._y;
	return *this;
}

Point Point::operator+(const Point& rValue)
{
	Point p = *this;
	p += rValue;
	return p;
}

