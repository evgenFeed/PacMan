#include "PacMan.h"

PacMan::PacMan(Point moveVector) :
	Tile('@', {1,1}),
	_moveVector(moveVector)
{
	
}

void PacMan::move()
{
	checkKeyboard();
	
	//this->setPosition(this->getPosition() += _moveVector);
}

void PacMan::checkKeyboard()
{
	if (GetAsyncKeyState(VK_UP) != 0) {
		_moveVector._x = 0;
		_moveVector._y = -1;
	}
	else if (GetAsyncKeyState(VK_DOWN) != 0) {
		_moveVector._x = 0;
		_moveVector._y = 1;
	}
	else if (GetAsyncKeyState(VK_LEFT) != 0) {
		_moveVector._x = -1;
		_moveVector._y = 0;
	}
	else if (GetAsyncKeyState(VK_RIGHT) != 0) {
		_moveVector._x = 1;
		_moveVector._y = 0;
	}
}


void PacMan::update()
{
	move();
}

void PacMan::draw()
{
	
}

Tile* PacMan::getTile()
{
	return &Tile::getTile();
}