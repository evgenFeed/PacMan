#pragma once
#include "Tile.h"
#include "Entity.h"
#include <string>
#include <deque>
class Ghost :
	public Tile, Entity
{
public:
	Ghost(std::string name);
	void move();
private:
	std::string _name;
	std::string _state;
	std::deque<Point> dequeMoves;
	std::deque<Point> dequeMovesWave;
	
};

 