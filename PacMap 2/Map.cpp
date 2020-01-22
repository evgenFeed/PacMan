#include "Map.h"

Map::Map()
{
	mapLoading();
}

void Map::draw()
{

	for (int i = 0; i < _tiles.size(); i++) {
		for (int j = 0; j < _tiles[i].size(); j++) {
			std::cout << _tiles[i][j]->getChar();
		}
		std::cout << std::endl;
	}
}

void Map::draw(Tile& tile)
{
	_tiles[tile.getPosition()._y][tile.getPosition()._x] = &tile;
}

std::vector<std::vector<Tile*>> Map::getTiles()
{
	return _tiles;
}

void Map::update()
{
	
}



void Map::mapLoading()
{
	FILE* file;
	if (file = fopen("map.txt", "r")) {
		char buff = getc(file);
		for (int i = 0; i < MAPSIZEY; i++) {
			_tiles.push_back(std::vector<Tile*>());
			for (int j = 0; j < MAPSIZEX+1; j++) {
				if (buff == '\n') {
					buff = getc(file);
				}
				else {
					_tiles[i].push_back(tileType(buff, Point{ i,j }));
					buff = getc(file);
				}
			}
		}
	}
	else {
		std::cout << "File map.txt missing or something is wrong!" << std::endl;
	}
}

Tile* Map::tileType(char tile, Point position)
{
	Tile* tempTile;
	switch (tile)
	{
	case '#':
		tempTile = new WallTile(tile, position);
		break;
	case '+':
		tempTile = new FoodTile(tile, position);
		break;
	case ' ':
		tempTile = new VoidTile(tile, position);
		break;
	case '-':
		tempTile = new DoorTile(tile, position);
		break;
	case 'e':
		tempTile = new EnergizerTile(tile, position);
		break;
	default: 
		tempTile = new VoidTile(tile, position);
		break;
	}
	return tempTile;
}
