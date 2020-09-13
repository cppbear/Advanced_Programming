#include "Interface.h"

Map map;
bool active = true;
int score = 0;
MODE mode = EASY;

int main()
{
	HideCursor();
	Color();
	Interface Tank;
	Tank.menu();
	return 0;
}
