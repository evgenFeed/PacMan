#pragma once
#include "Point.h"
class Tile
{
public:
	Tile(char tile, Point position);
	Tile(const Tile& tile);
	Tile getTile();
	Point getPosition()const;
	char getChar();
protected:
	void setPosition(Point position);
private:
	Point _position;
	char _tile;	
};

