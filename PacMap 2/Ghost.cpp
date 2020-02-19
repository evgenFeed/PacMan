#include "Ghost.h"

Ghost::Ghost(std::string name) :
	Tile('B', "Ghost", {14,11}),
	_name(name),
	_state("scatter")
{
	
}

void Ghost::move()
{
	Point nextMove = dequeMoves.back();
	Point oldPos = this->getPosition();
	dequeMoves.pop_back();
	this->setPosition(oldPos+nextMove);
}

void Ghost::update(std::deque<Point> moves)
{
	dequeMoves = moves;
	move();
}
