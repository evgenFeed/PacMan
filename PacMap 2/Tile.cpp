#include "Tile.h"

Tile::Tile(char tile, Point position) :
	_tile(tile),
	_position(position)
{
}

Tile::Tile(const Tile& tile):
	_position(tile._position),
	_tile(tile._tile)
{
}

Tile Tile::getTile()
{
	return *this;
}

Point Tile::getPosition() const
{
	return _position;
}

char Tile::getChar()
{
	return _tile;
}

void Tile::setPosition(Point position)
{
	_position = position;
}
