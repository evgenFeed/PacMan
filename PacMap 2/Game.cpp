#include "Game.h"

Game::Game():
	_pac(),
	_map(),
	_score(0)
{
	
}

void Game::run()
{
	while (true)
	{
		draw();
		update();
		clear();
	}
	//draw();
}

void Game::draw()
{
	//_pac.draw();
	_map.draw(_pac.getTile());
	_map.draw();
}

void Game::update()
{
	_map.update(_pac.update(checkNextChar()));
}

void Game::clear()
{
	system("cls");
}

char Game::checkNextChar()
{
	Point nextStep = { _pac.getPosition()._x + _pac.getMoveVector()._x, _pac.getPosition()._y + _pac.getMoveVector()._y };
	char nextStepChar = _map.getTiles()[nextStep._y][nextStep._x]->getChar();
	return nextStepChar;
}
