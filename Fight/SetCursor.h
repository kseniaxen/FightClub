#pragma once
#include <Windows.h>
bool SetCursorPosition(short x, short y)
{
	COORD coord = { x, y };
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}