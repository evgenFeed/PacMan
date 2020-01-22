#pragma once
#include "Map.h"
#include "PacMan.h"

class Game
{
public:
	Game();
	void run();
private:
	void draw();
	void update();
	void clear();
	Map _map;
	PacMan _pac;
};

