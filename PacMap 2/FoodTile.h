#pragma once
#include "Tile.h"
class FoodTile :
	public Tile
{
public:
	FoodTile(char tile, std::string type, Point position);
};

