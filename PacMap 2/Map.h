#pragma once
#include <iostream>
#include <vector>
#include "Tile.h"
#include "WallTile.h"
#include "FoodTile.h"
#include "VoidTile.h"
#include "DoorTile.h"
#include "EnergizerTile.h"

class Map
{
public:
	Map();
	void draw();
	void update();
	void draw(Tile& tile);
	std::vector<std::vector<Tile*>> getTiles();
private:
	std::vector<std::vector<Tile*>> _tiles;
	void mapLoading();
	Tile* tileType(char tile, Point position);

	const int MAPSIZEX = 28;
	const int MAPSIZEY = 31;
};

