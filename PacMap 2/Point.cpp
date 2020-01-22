#include "Point.h"

Point& Point::operator+=(const Point& rValue)
{
	_x += rValue._x;
	_y += rValue._y;
	return *this;
}
