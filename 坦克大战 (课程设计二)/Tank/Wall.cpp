#include "Wall.h"
using namespace std;

void Wall::draw(bool filling)
{
	if (filling)
	{
		drawAtPoint(x, y, "〓", ORANGE);
	}
	else
		drawAtPoint(x, y, "  ", "");
}

void IronWall::draw(bool filling)
{
	if (filling)
	{
		drawAtPoint(x, y, "〓", GREY);
	}
	else
		drawAtPoint(x, y, "  ", "");
}

void Base::draw(bool filling)
{
	if (filling)
	{
		drawAtPoint(x, y, "◆", RED);
	}
	else
		drawAtPoint(x, y, "  ", "");
}
