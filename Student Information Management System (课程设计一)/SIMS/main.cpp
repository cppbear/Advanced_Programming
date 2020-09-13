#include "Interface.h"
using namespace std;

// 隐藏光标
void HideCursor()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &cci);
}

// 让Windows中的控制台也能正确显示用"\033[0m"等表示的颜色
void Color()
{
	const auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(handle, &mode);
	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(handle, mode);
}

int main()
{
	HideCursor();
	//Color();
	Interface SIMS;
	int res = SIMS.run();
	return res;
}
