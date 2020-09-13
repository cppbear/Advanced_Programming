#include "Buff.h"

void Buff::draw(bool filling)
{
	string buff;
	if (filling)
	{
		switch (bufftype)
		{
		case LIFEBUFF:
			drawAtPoint(x, y, "◎", RED);
			break;
		case SPEEDBUFF:
			drawAtPoint(x, y, "◎", BLUE);
			break;
		case POWERBUFF:
			drawAtPoint(x, y, "◎", YELLOW);
			break;
		case VOLUMEBUFF:
			drawAtPoint(x, y, "◎", GREEN);
			break;
		default:
			break;
		}
	}
	else
	{
		drawAtPoint(x, y, "  ", "");
	}
}
