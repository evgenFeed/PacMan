#pragma once
#include "Entity.h"
#include <Windows.h>


class PacMan :
	public Entity, public Tile
{
public:
			PacMan(Point moveVector = {0,0});
	Tile*	update(char nextChar);
	void	draw();
	Tile*	getTile();
	Point	getMoveVector()const;
private:
	Point			_moveVector;
	std::string		_state;

	void	move();
	Tile*	move(char nextChar);
	void	checkKeyboard();
};

