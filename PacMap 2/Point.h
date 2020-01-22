#pragma once
class Point
{
public:
	int _x;
	int _y;

	Point& operator+=(const Point& rValue);
};

