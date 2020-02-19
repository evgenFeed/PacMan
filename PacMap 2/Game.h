#pragma once
#include "Map.h"
#include "PacMan.h"
#include "Ghost.h"
#include <deque>

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
	std::deque<Point> findPath();
	Map _map;
	PacMan _pac;
	Ghost _ghost;
	int _score;

};

