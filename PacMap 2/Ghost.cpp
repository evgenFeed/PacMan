#include "Ghost.h"

Ghost::Ghost(std::string name) :
	Tile('B', "Ghost", {14,11}),
	_name(name),
	_state("scatter")
{
	
}

void Ghost::move()
{
}
