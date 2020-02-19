#pragma once
class Point
{
public:
	int _x;
	int _y;

	Point& operator+=(const Point& rValue);
	bool operator==(const Point& rValue) {
		return (this->_x == rValue._x && this->_y == rValue._y);
	}
	Point operator+(const Point& rValue);
};

