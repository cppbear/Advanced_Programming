#pragma once
#include "Bullet.h"
#include "Map.h"
using namespace std;
extern Map map;
extern bool active;
extern int score;

class Tank : public Element
{
protected:
	short life, speed, power, volume;
	DIR direct;
	CAMP camp;

public:
	vector<Bullet*> bullets;
	Tank(short x_, short y_, CAMP camp_);
	void changeDirect(DIR dir);
	void move(DIR dir);
	virtual void draw(bool filling);
	virtual void addBullet();
	bool collisionTurn();
	bool collisionForward(DIR dir);
	bool reduceLife(short damage);
	void addLife(bool force, short val);
	void addSpeed(short val);
	void powerUp();
	void volumeUP();
	int getLife() { return life; }
	int getPower() { return power; }
	int getVolume() { return volume; }
	int getSpeed() { return speed; }
	CAMP getCamp() { return camp; }
};

inline Tank::Tank(short x_, short y_, CAMP camp_)
{
	type = TANK;
	camp = camp_;
	life = 3;
	speed = 1;
	power = 1;
	volume = 5;
	x = x_;
	y = y_;
	direct = UP;
	map.map[y - 1][x / 2] = this;
	map.map[y][x / 2] = map.map[y][(x - 2) / 2] = map.map[y][(x + 2) / 2] = this;
	map.map[y + 1][x / 2] = map.map[y + 1][(x - 2) / 2] = map.map[y + 1][(x + 2) / 2] = this;
}

class ArmoredCar : public Tank
{
public:
	ArmoredCar(short x, short y, CAMP camp_);
};

inline ArmoredCar::ArmoredCar(short x_, short y_, CAMP camp_) :Tank(x_, y_, camp_)
{
	type = TANK;
	speed = 2;
	life = 4;
}

class HeavyTank : public Tank
{
public:
	HeavyTank(short x_, short y_, CAMP camp_);
};

inline HeavyTank::HeavyTank(short x_, short y_, CAMP camp_) :Tank(x_, y_, camp_)
{
	type = TANK;
	power = 2;
	life = 5;
}

class DoubleTank : public Tank
{
public:
	DoubleTank(short x_, short y_, CAMP camp_);
	void draw(bool filling);
	virtual void addBullet();
};

inline DoubleTank::DoubleTank(short x_, short y_, CAMP camp_) :Tank(x_, y_, camp_)
{
	type = TANK;
	power = 1;
	life = 4;
}
