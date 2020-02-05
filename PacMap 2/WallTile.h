#pragma once
#include "Tile.h"
class WallTile :
	public Tile
{
public:
	WallTile(char tile, std::string type, Point position);
};

