#pragma once
#include <Windows.h>
/*
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      // Black
#define RED     "\033[31m"      // Red
#define GREEN   "\033[32m"      // Green
#define YELLOW  "\033[33m"      // Yellow
#define BLUE    "\033[34m"      // Blue
#define MAGENTA "\033[35m"      // Magenta
#define CYAN    "\033[36m"      // Cyan
#define WHITE   "\033[37m"      // White
*/

#define RESET	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
#define RED		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED)
#define GREEN	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN)
#define BLUE	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE)
#define YELLOW  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN)
#define CYAN	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE)
#define MAGENTA SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE)
#define WHITE	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
