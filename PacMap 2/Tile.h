#pragma once
#include "Point.h"
#include <string>

class Tile
{
public:
	Tile(char tile, std::string type, Point position);
	Tile* getTile();
	Point getPosition()const;
	char getChar();
	std::string getType();
protected:
	void setPosition(Point position);
private:
	Point _position;
	char _tile;	
	std::string _type;
};

