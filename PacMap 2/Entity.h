#pragma once
#include "Tile.h"
#include "VoidTile.h"
#include "EnergizerTile.h"
#include "FoodTile.h"
#include "WallTile.h"

class Entity
{
protected:
	virtual void move() = 0;
};

