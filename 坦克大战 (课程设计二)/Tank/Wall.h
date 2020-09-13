#pragma once
#include "config.h"

class Wall : public Element
{
public:
	Wall(short x, short y);
	virtual void draw(bool filling);
};

inline Wall::Wall(short x, short y)
{
	this->x = x;
	this->y = y;
	type = WALL;
	draw(true);
}

class IronWall : public Wall
{
public:
	IronWall(short x, short y);
	void draw(bool filling);
};

inline IronWall::IronWall(short x, short y) : Wall(x, y)
{
	type = IRONWALL;
	draw(true);
}

class Base : public Wall
{
public:
	Base(short x, short y);
	void draw(bool filling);
};

inline Base::Base(short x, short y) : Wall(x, y)
{
	type = BASE;
	draw(true);
}
