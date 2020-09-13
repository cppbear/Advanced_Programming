#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <conio.h>
#include <stdlib.h>
#include <ctime>

//#define DEBUG

#define HEIGHT 36
#define WIDTH 100
enum MODE { EASY, NORMAL, HARD };
enum CAMP { SELF, FRIEND, ENEMY };
enum DIR { UP, DOWN, LEFT, RIGHT };
enum TYPE { WALL, IRONWALL, BASE, TANK, BULLET, BUFF };
enum BUFFTYPE { LIFEBUFF, SPEEDBUFF, POWERBUFF, VOLUMEBUFF };

#define RESET   "\033[0m"
#define BLACK   "\033[30m"		// Black
#define RED     "\033[31m"		// Red
#define GREEN   "\033[32m"		// Green
#define YELLOW  "\033[33m"		// Yellow
#define BLUE    "\033[34m"		// Blue
#define MAGENTA "\033[35m"		// Magenta
#define CYAN    "\033[36m"		// Cyan
#define WHITE   "\033[37m"		// White
#define ORANGE	"\033[38;2;255;102;0m"		// Orange
#define GREY	"\033[38;2;190;190;190m"	// Grey
#define GOLD	"\033[38;2;255;215;0m"		// Gold

inline void Color()
{
	const auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(handle, &mode);
	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(handle, mode);
}

inline void HideCursor()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &cci);
}

inline void drawAtPoint(short x, short y, const char* str, const char* color)
{
	HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point = { x, y };
	SetConsoleCursorPosition(HOutput, point);
	std::string temp = color + (std::string)str + RESET;
	printf(temp.c_str());
}

class Element
{
protected:
	short x, y;
	TYPE type;
public:
	TYPE getType() { return type; }
	virtual void draw(bool filling) = 0;
};

#define TEST Sleep(10);				\
for (int i = 0; i < 36; i++)		\
	for (int j = 0; j < 50; j++)	\
		if (map.map[i][j])		\
		{	\
			int temp = map.map[i][j]->getType();	\
			if (temp == 0)		\
				drawAtPoint(j * 2, i, "00");		\
			else	\
			{		\
				temp += (temp * 10);	\
				drawAtPoint(j * 2, i, to_string(temp).c_str());	\
			}	\
		}	\
