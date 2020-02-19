#include "Game.h"
#ifdef _DEBUG
#include <iomanip>
#endif

Game::Game():
	_pac(),
	_map(),
	_score(0),
	_ghost("Blinki")
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
	_pac.draw();
	_map.draw(_pac.getTile());
	_map.draw(_ghost.getTile());
	_map.draw();
}

void Game::update()
{
	_ghost.update(findPath());
	_map.update(&_ghost);
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
std::deque<Point> Game::findPath()
{
	int d = 0; //вес
	Point from;		//точко "от"
	Point to;		//точка "до"
	bool found = false; //флаг "найдено"
	bool pathReady = false;
	std::deque<Point> steps; //очередь шагов волны
	std::deque<Point> pathMoves; //шаги до цели
	Point wave, backWave; // где находится (обратная) волна сейчас
	std::vector<std::vector<int>> weights; //"весы"
	for (int i = 0; i <= 31; i++) {
		weights.push_back(std::vector<int>(28));
		for (int j = 0; j < 28; j++) {
			weights.at(i).at(j) = -1;
		}
	}
	from = _ghost.getPosition(); //точка "от" - призрак
	to = _pac.getPosition(); //точка "до" - пакман
	wave = from; //установка волны в точку "от"
	weights.at(from._y).at(from._x) = d; //начальной точке ставится вес = 0
	enum SIDES {
		UP = -1,
		DOWN = 1,
		LEFT = -1,
		RIGHT = 1
	};

	while (!found)
	{
		int y = wave._y, x = wave._x;
		if (x == 27 || x == 0) {
			wave = steps.front();
			steps.pop_front();
			y = wave._y, x = wave._x;
			d = weights.at(y).at(x);
		}
		if (x == to._x && y == to._y) {
			found = true;
			backWave = { x,y };
			continue;
		}
		if (_map.getTiles().at(y + UP).at(x)->getChar() != '#') {
			if (weights.at(y + UP).at(x) == -1) {
				weights.at(y + UP).at(x) = d + 1;
				steps.push_back(Point{ x,y + UP });
			}
			else {

			}
		}
		if (_map.getTiles().at(y).at(x + RIGHT)->getChar() != '#') {
			if (weights.at(y).at(x + RIGHT) == -1) {
				weights.at(y).at(x + RIGHT) = d + 1;
				steps.push_back(Point{ x + RIGHT, y });
			}
			else {

			}
		}
		if (_map.getTiles().at(y + DOWN).at(x)->getChar() != '#') {
			if (weights.at(y + DOWN).at(x) == -1) {
				weights.at(y + DOWN).at(x) = d + 1;
				steps.push_back(Point{ x,y + DOWN });
			}
			else {

			}
		}
		if (_map.getTiles().at(y).at(x + LEFT)->getChar() != '#') {
			if (weights.at(y).at(x + LEFT) == -1) {
				weights.at(y).at(x + LEFT) = d + 1;
				steps.push_back(Point{ x + LEFT,y });
			}
			else {

			}
		}
		if (!steps.empty()) {
			wave = steps.front();
			steps.pop_front();
			d = weights.at(wave._y).at(wave._x);
		}
		else {
		}
	}
	while (!pathReady) {
		//backWave = to;
		if (backWave == from) {
			pathReady = true;
			continue;
		}
		int x = backWave._x, y = backWave._y;
		d = weights.at(backWave._y).at(backWave._x);
		if (weights.at(backWave._y + UP).at(backWave._x) < d && weights.at(backWave._y + UP).at(backWave._x) != -1) {
			Point temp{ x - x, y - (y + UP) };
			pathMoves.push_back(temp);
			backWave = { backWave._x, backWave._y + UP };
		}
		else if (weights.at(backWave._y).at(backWave._x + RIGHT) < d && weights.at(backWave._y).at(backWave._x + RIGHT) != -1) {
			Point temp{ x - (x + RIGHT), y - y };
			pathMoves.push_back(temp);
			backWave = { backWave._x + RIGHT, backWave._y };
		}
		else if (weights.at(backWave._y + DOWN).at(backWave._x) < d && weights.at(backWave._y + DOWN).at(backWave._x) != -1) {
			Point temp{ x - x, y - (y + DOWN) };
			pathMoves.push_back(temp);
			backWave = { backWave._x, backWave._y + DOWN };
		}
		else if (weights.at(backWave._y).at(backWave._x + LEFT) < d && weights.at(backWave._y).at(backWave._x + LEFT) != -1) {
			Point temp{ x - (x + LEFT), y - y };
			pathMoves.push_back(temp);
			backWave = { backWave._x + LEFT, backWave._y };
		}
	}
	return pathMoves;
}
