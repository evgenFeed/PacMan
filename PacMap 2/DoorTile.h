#pragma once
#include "Tile.h"
class DoorTile :
	public Tile
{
public:
	DoorTile(char tile, std::string type, Point position);
};

