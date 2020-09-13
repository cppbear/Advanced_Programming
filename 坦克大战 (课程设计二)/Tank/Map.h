#pragma once
#include "Wall.h"

class Map
{
	friend class Tank;
	friend class Bullet;
	friend class Buff;

private:
	

public:
	Element* map[HEIGHT][WIDTH / 2] = {};
	Map() {}
	void createWall();
};
