#pragma once
#include "Entity.h"
#include <Windows.h>


class PacMan :
	public Entity, public Tile
{
public:
	PacMan(Point moveVector = {0,0});
	//GetAsyncKeyState
	void update(bool canMove);
	void draw();
	Tile* getTile();
	Point getMoveVector()const;
private:
	Point _moveVector;
	void move();
	void move(bool canMove);
	void checkKeyboard();
};

