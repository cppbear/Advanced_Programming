#pragma once
#include "config.h"
#include "Map.h"
using namespace std;
extern Map map;
extern bool active;

class Tank;

class Bullet : public Element
{
protected:
	short speed, power;
	DIR direct;
	bool coll;
	Tank *belong;
public:
	Bullet(short x, short y, DIR direct, Tank *be, short po);
	int run();
	void draw(bool filling);
	bool collision();
	bool is_coll() { return coll; }
};

inline Bullet::Bullet(short x, short y, DIR direct, Tank *be, short po)
{
	coll = false;
	belong = be;
	power = po;
	type = BULLET;
	speed = 1;
	this->direct = direct;
	switch (direct)
	{
	case UP:
		this->x = x;
		this->y = y - 1;
		break;
	case DOWN:
		this->x = x;
		this->y = y + 1;
		break;
	case LEFT:
		this->x = x - 2;
		this->y = y;
		break;
	case RIGHT:
		this->x = x + 2;
		this->y = y;
		break;
	default:
		break;
	}
	//map.map[y][x / 2] = this;
}
