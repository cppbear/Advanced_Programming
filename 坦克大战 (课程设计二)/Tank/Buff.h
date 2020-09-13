#pragma once
#include "config.h"
#include "Map.h"
using namespace std;
extern Map map;

class Buff : public Element
{
private:
	BUFFTYPE bufftype;
public:
	Buff(short x_, short y_, TYPE type_, BUFFTYPE buff);
	void draw(bool filling);
	BUFFTYPE getBuff() { return bufftype; }
};

inline Buff::Buff(short x_, short y_, TYPE type_, BUFFTYPE buff)
{
	x = x_;
	y = y_;
	type = type_;
	bufftype = buff;
	map.map[y][x / 2] = this;
}
