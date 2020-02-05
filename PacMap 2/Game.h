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
	char checkNextChar();
	Map _map;
	PacMan _pac;
	int _score;

};

