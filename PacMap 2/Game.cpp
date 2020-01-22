#include "Game.h"

Game::Game():
	_pac(),
	_map()
{
	
}

void Game::run()
{
	/*while (true)
	{
		draw();
		update();
		clear();
	}*/
	draw();
}

void Game::draw()
{
	_pac.draw();
	_map.draw(_pac.getTile());
	_map.draw();
	
}

void Game::update()
{
	_pac.update();
	_map.update();
}

void Game::clear()
{
	system("cls");
}
