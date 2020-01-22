#pragma once
#include "Entity.h"
#include <Windows.h>


class PacMan :
	public Entity, public Tile
{
public:
	PacMan(Point moveVector = {0,0});
	//GetAsyncKeyState
	void update();
	void draw();
	Tile* getTile();
private:
	Point _moveVector;
	void move();
	void checkKeyboard();
};

