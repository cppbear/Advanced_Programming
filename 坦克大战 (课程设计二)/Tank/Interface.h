#pragma once
#include "Tank.h"
#include "Buff.h"

extern Map map;
extern bool active;
extern MODE mode;

class Interface
{
private:
	void boader();
	void menuface();
	void random(list<Tank*>& enemy, int &count);
	void status(list<Tank*> frie, list<Tank*> enemy, int &count);
	void buff();
	void win();
	void gameover();
	void setting();
public:
	Interface() {}
	int run();
	int menu();
};
