#include "Tile.h"

Tile::Tile(char tile, std::string type,Point position) :
	_tile(tile),
	_position(position),
	_type(type)
{
}

Tile* Tile::getTile()
{
	return this;
}

Point Tile::getPosition() const
{
	return this->_position;
}

char Tile::getChar()
{
	return _tile;
}

std::string Tile::getType()
{
	return _type;
}

void Tile::setPosition(Point position)
{
	_position = position;
}
