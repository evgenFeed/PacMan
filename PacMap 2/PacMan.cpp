#include "PacMan.h"

PacMan::PacMan(Point moveVector) :
	Tile('@', "PacMan", { 1,1 }),
	_moveVector(moveVector),
	_state("moving")
{
	
}

void PacMan::move()
{
}

Tile* PacMan::move(char nextChar)
{
	checkKeyboard();
	Tile* temp;
	if (nextChar != '#') {
		Point oldPos = this->getPosition();
		this->setPosition(this->getPosition() += _moveVector);
		if (nextChar == '+') {
			temp = new VoidTile(' ', "void", oldPos);
			return temp;
		}
		else if (nextChar == 'e') {
			_state = "energized";
			temp = new VoidTile(' ', "void", oldPos);
			return temp;
		}
		else if (nextChar == ' ') {
			temp = new VoidTile(' ', "void", oldPos);
			return temp;
		}
		else if (nextChar == '@') {
			temp = new VoidTile(' ', "void", oldPos);
			return temp;
		}
	}
	else {
		_moveVector = { 0,0 };
		return this;
	}
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


Tile* PacMan::update(char nextChar)
{
	return move(nextChar);
}

void PacMan::draw()
{
	
}

Tile* PacMan::getTile()
{
	return Tile::getTile();
}

Point PacMan::getMoveVector() const
{
	return _moveVector;
}
